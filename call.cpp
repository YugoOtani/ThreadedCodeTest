#include "insn.h"
#include <iostream>

static int *sp, stack[100], result;
static bool iserr;
clock_t st, ed;
extern void exec_asm();

void handler_nop()
{
    return;
}
void handler_int0()
{
    *sp++ = 0;
}
void handler_int1()
{
    *sp++ = 1;
}
void handler_int2()
{
    *sp++ = 2;
}

void handler_int3()
{
    *sp++ = 3;
}
void handler_int4()
{
    *sp++ = 4;
}
void handler_int5()
{
    *sp++ = 5;
}
void handler_int6()
{
    *sp++ = 6;
}
void handler_int7()
{
    *sp++ = 7;
}
void handler_int8()
{
    *sp++ = 8;
}
void handler_add()
{
    sp[-2] += sp[-1];
    sp--;
}
void handler_sub()
{
    sp[-2] -= sp[-1];
    sp--;
}
void handler_mul()
{
    sp[-2] *= sp[-1];
    sp--;
}
void handler_div()
{
    sp[-2] /= sp[-1];
    sp--;
}
void handler_ret()
{
    result = sp[-1];
    iserr = false;
    return;
}

void exec()
{
    sp = &stack[0];
    st = clock();
    exec_asm();
    ed = clock();
}
int main(void)
{
    exec();
    std::cout << ed - st << std::endl;
}
