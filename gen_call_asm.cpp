#include <iostream>
#include <fstream>
#include "insn.h"

std::string input_path = "bytecode/bytecode.txt";
std::string output_path = "call_exec.s";
int main(int argc, char *argv[])
{
    if (argc > 1)
        input_path = argv[1];
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
    std::ofstream outfile(output_path);
    outfile << "    .global __Z8exec_asmv\n";
    outfile << "    .p2align 2\n";
    outfile << "__Z8exec_asmv:\n";
    outfile << "    stp x29, x30, [sp, #-16]!\n";
    outfile << "    mov x29, sp\n";
    for (auto insn : bytecode)
    {
        switch (insn)
        {
        case Insn::INT0:
            outfile << "    bl __Z12handler_int0v\n";
            break;
        case Insn::INT1:
            outfile << "    bl __Z12handler_int1v\n";
            break;
        case Insn::INT2:
            outfile << "    bl __Z12handler_int2v\n";
            break;
        case Insn::INT3:
            outfile << "    bl __Z12handler_int3v\n";
            break;
        case Insn::INT4:
            outfile << "    bl __Z12handler_int4v\n";
            break;
        case Insn::INT5:
            outfile << "    bl __Z12handler_int5v\n";
            break;
        case Insn::INT6:
            outfile << "    bl __Z12handler_int6v\n";
            break;
        case Insn::INT7:
            outfile << "    bl __Z12handler_int7v\n";
            break;
        case Insn::INT8:
            outfile << "    bl __Z12handler_int8v\n";
            break;
        case Insn::ADD:
            outfile << "    bl __Z11handler_addv\n";
            break;
        case Insn::SUB:
            outfile << "    bl __Z11handler_subv\n";
            break;
        case Insn::MUL:
            outfile << "    bl __Z11handler_mulv\n";
            break;
        case Insn::DIV:
            outfile << "    bl __Z11handler_divv\n";
            break;
        case Insn::RETURN:
            outfile << "    bl __Z11handler_retv\n";
            outfile << "    ldp x29, x30, [sp], #16\n";
            outfile << "    ret\n";
            break;
        case Insn::NOP:
            outfile << "    bl __Z11handler_nopv \n";
            break;
        }
    }
}
