#include "mytrace.h"

void foo1(void);
void foo2(void);
void foo3(void);
void foo4(void);
void foo5(void);
void foo6(void);
void foo7(void);


void foo1() { foo2();  };
void foo2() { foo3();  };
void foo3() { foo4();  };
void foo4() { foo5();  };
void foo5() { foo6();  };
void foo6() { foo7();  };
void foo7() { };






int main()
{
	foo1();
	foo4();
	mytrace_dump();
	return 0;
}
