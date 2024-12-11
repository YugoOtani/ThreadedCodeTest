#include "insn.h"
#include <vector>
#include <iostream>
#include <fstream>

int *sp, stack[100], result;
unsigned char *pc;
clock_t st, ed;
bool iserr;
std::string input_path = "bytecode/bytecode.txt";

void exec(std::vector<unsigned char> bytecode)
{
    pc = &bytecode[0];
    sp = &stack[0];
    static void *dispatch_table[] = {
        &&nop,
        &&int0,
        &&int1,
        &&int2,
        &&int3,
        &&int4,
        &&int5,
        &&int6,
        &&int7,
        &&int8,
        &&add,
        &&sub,
        &&mul,
        &&div,
        &&ret,
    };
    st = clock();
#define DISPATCH() goto *dispatch_table[*pc++]
    DISPATCH();

nop:
    DISPATCH();
int0:
    *sp++ = 0;
    DISPATCH();
int1:
    *sp++ = 1;
    DISPATCH();
int2:
    *sp++ = 2;
    DISPATCH();
int3:
    *sp++ = 3;
    DISPATCH();
int4:
    *sp++ = 4;
    DISPATCH();
int5:
    *sp++ = 5;
    DISPATCH();
int6:
    *sp++ = 6;
    DISPATCH();
int7:
    *sp++ = 7;
    DISPATCH();
int8:
    *sp++ = 8;
    DISPATCH();
add:
    sp[-2] += sp[-1];
    sp--;
    DISPATCH();
sub:
    sp[-2] -= sp[-1];
    sp--;
    DISPATCH();
mul:
    sp[-2] *= sp[-1];
    sp--;
    DISPATCH();
div:
    sp[-2] /= sp[-1];
    sp--;
    DISPATCH();
ret:
    result = sp[-1];
    iserr = false;
}
int main(int argc, char *argv[])
{
    std::ifstream infile(input_path);
    if (!infile)
    {
        std::cerr << "No input file.\n";
        return 1;
    }
    std::vector<unsigned char> bytecode;
    std::string line;
    while (std::getline(infile, line))
        bytecode.push_back(std::stoi(line));
    infile.close();
    for (int i = 0; i < 1000; i++)
    {
        exec(bytecode);
        ed = clock();
        std::cout << ed - st << std::endl;
    }
}
