#pragma once
#include <memory>
#include <vector>
#include "../insn.h"
typedef struct Expr
{

    enum kind
    {
        None,
        Add,
        Sub,
        Term
    } kind;
    std::unique_ptr<struct Expr> lhs;
    std::unique_ptr<struct Term> rhs;
    std::unique_ptr<struct Term> term;
    Expr(enum kind kind, std::unique_ptr<struct Expr> lhs, std::unique_ptr<struct Term> rhs);
    Expr(std::unique_ptr<struct Term> term);

    static std::unique_ptr<Expr> createAdd(std::unique_ptr<struct Expr> lhs, std::unique_ptr<struct Term> rhs);
    static std::unique_ptr<Expr> createSub(std::unique_ptr<struct Expr> lhs, std::unique_ptr<struct Term> rhs);
    static std::unique_ptr<Expr> createTerm(std::unique_ptr<struct Term> term);
    void eval(std::vector<Insn> &result);

} Expr;

typedef struct Term
{
    enum kind
    {
        None,
        Mul,
        Div,
        Factor
    } kind;

    std::unique_ptr<struct Term> lhs;
    std::unique_ptr<struct Factor> rhs;
    std::unique_ptr<struct Factor> factor;

    Term(enum kind kind, std::unique_ptr<struct Term> lhs, std::unique_ptr<struct Factor> rhs);
    Term(std::unique_ptr<struct Factor> factor);

    static std::unique_ptr<Term> createMul(std::unique_ptr<struct Term> lhs, std::unique_ptr<struct Factor> rhs);
    static std::unique_ptr<Term> createDiv(std::unique_ptr<struct Term> lhs, std::unique_ptr<struct Factor> rhs);
    static std::unique_ptr<Term> createFactor(std::unique_ptr<struct Factor> factor);
    void eval(std::vector<Insn> &result);
} Term;
typedef struct Factor
{
    enum kind
    {
        Number,
        Expr,
    } kind;
    int number;
    std::unique_ptr<struct Expr> expr;

    Factor(int number);
    Factor(std::unique_ptr<struct Expr> expr);

    static std::unique_ptr<Factor> createNumber(int number);
    static std::unique_ptr<Factor> createExpr(std::unique_ptr<struct Expr> expr);
    void eval(std::vector<Insn> &result);
} Factor;
