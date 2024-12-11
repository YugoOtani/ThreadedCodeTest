#include "insn.h"
#include <vector>
#include <iostream>
#include <fstream>

int *sp, stack[100], result;
clock_t st, ed;
unsigned char *pc;
std::string input_path = "bytecode/bytecode.txt";

void exec(std::vector<unsigned char> bytecode)
{
    pc = &bytecode[0];
    sp = &stack[0];

    st = clock();
    while (true)
    {
        switch (*pc++)
        {
        case Insn::NOP:
            break;
        case Insn::INT0:
            *sp++ = 0;
            break;
        case Insn::INT1:
            *sp++ = 1;
            break;
        case Insn::INT2:
            *sp++ = 2;
            break;
        case Insn::INT3:
            *sp++ = 3;
            break;
        case Insn::INT4:
            *sp++ = 4;
            break;
        case Insn::INT5:
            *sp++ = 5;
            break;
        case Insn::INT6:
            *sp++ = 6;
            break;
        case Insn::INT7:
            *sp++ = 7;
            break;
        case Insn::INT8:
            *sp++ = 8;
            break;
        case Insn::ADD:
            sp[-2] += sp[-1];
            sp--;
            break;
        case Insn::SUB:
            sp[-2] -= sp[-1];
            sp--;
            break;
        case Insn::MUL:
            sp[-2] *= sp[-1];
            sp--;
            break;
        case Insn::DIV:
            sp[-2] /= sp[-1];
            sp--;
            break;
        case Insn::RETURN:
            result = sp[-1];
            return;
        default:
            return;
        }
    }
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
