#include <stdio.h>
#include "mytrace.h"

#define CONFIG_LOGBUF_DEPTH		30
 
struct TRACEBUF
{
	void *son;
	void *parent;
} tracebuf[CONFIG_LOGBUF_DEPTH];

int tracebuf_curr_idx;
 
 
void __attribute__((no_instrument_function))
__cyg_profile_func_enter(void *this_func, void *call_site)
{
	if (tracebuf_curr_idx == CONFIG_LOGBUF_DEPTH)
		tracebuf_curr_idx = 0;

	tracebuf[tracebuf_curr_idx].son = this_func;
	tracebuf[tracebuf_curr_idx].parent = call_site;
	++tracebuf_curr_idx;
}
 
void __attribute__((no_instrument_function))
__cyg_profile_func_exit(void *this_func, void *call_site)
{
}


void __attribute__((no_instrument_function))
mytrace_dump(void)
{
	int i = tracebuf_curr_idx + 1;

	if (i == CONFIG_LOGBUF_DEPTH)
		i = 0;

	while (i != tracebuf_curr_idx) {
		if (tracebuf[i].son && tracebuf[i].parent)
			printf("%p - %p\n", tracebuf[i].son, tracebuf[i].parent);

		i++;
		if (i == CONFIG_LOGBUF_DEPTH)
			i = 0;
	}
}
