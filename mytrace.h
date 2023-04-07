#ifndef _MYTRACE_H_
#define _MYTRACE_H_

#include <unistd.h>
#include <signal.h>

void __attribute__((no_instrument_function)) mytrace_dump(void);
void __attribute__((no_instrument_function)) mytrace_sig_handler(int signum);

#endif
