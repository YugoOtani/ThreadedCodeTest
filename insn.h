#pragma once
typedef enum Insn : unsigned char
{
    NOP,
    INT0,
    INT1,
    INT2,
    INT3,
    INT4,
    INT5,
    INT6,
    INT7,
    INT8,
    ADD,
    SUB,
    MUL,
    DIV,
    RETURN,
} Insn;