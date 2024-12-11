#include "ast.h"
#include <memory>
#include <iostream>
Expr::Expr(enum kind kind, std::unique_ptr<struct Expr> lhs, std::unique_ptr<struct Term> rhs)
    : kind(kind), lhs(std::move(lhs)), rhs(std::move(rhs)), term(nullptr) {}
Expr::Expr(std::unique_ptr<struct Term> term)
    : kind(Term), term(std::move(term)), lhs(nullptr), rhs(nullptr) {}

std::unique_ptr<Expr> Expr::createAdd(std::unique_ptr<struct Expr> lhs, std::unique_ptr<struct Term> rhs)
{
    return std::make_unique<Expr>(Add, std::move(lhs), std::move(rhs));
}
std::unique_ptr<Expr> Expr::createSub(std::unique_ptr<struct Expr> lhs, std::unique_ptr<struct Term> rhs)
{
    return std::make_unique<Expr>(Sub, std::move(lhs), std::move(rhs));
}
std::unique_ptr<Expr> Expr::createTerm(std::unique_ptr<struct Term> term)
{
    return std::make_unique<Expr>(std::move(term));
}

Term::Term(enum kind kind, std::unique_ptr<struct Term> lhs, std::unique_ptr<struct Factor> rhs)
    : kind(kind), lhs(std::move(lhs)), rhs(std::move(rhs)), factor(nullptr) {}
Term::Term(std::unique_ptr<struct Factor> factor)
    : kind(Factor), factor(std::move(factor)), lhs(nullptr), rhs(nullptr) {}

std::unique_ptr<Term> Term::createMul(std::unique_ptr<struct Term> lhs, std::unique_ptr<struct Factor> rhs)
{
    return std::make_unique<Term>(Mul, std::move(lhs), std::move(rhs));
}
std::unique_ptr<Term> Term::createDiv(std::unique_ptr<struct Term> lhs, std::unique_ptr<struct Factor> rhs)
{
    return std::make_unique<Term>(Div, std::move(lhs), std::move(rhs));
}
std::unique_ptr<Term> Term::createFactor(std::unique_ptr<struct Factor> factor)
{
    return std::make_unique<Term>(std::move(factor));
}

Factor::Factor(int number)
    : kind(Number), number(number), expr(nullptr) {}
Factor::Factor(std::unique_ptr<struct Expr> expr)
    : kind(Expr), expr(std::move(expr)), number(0) {}

std::unique_ptr<Factor> Factor::createNumber(int number)
{
    return std::make_unique<Factor>(number);
}
std::unique_ptr<Factor> Factor::createExpr(std::unique_ptr<struct Expr> expr)
{
    return std::make_unique<Factor>(std::move(expr));
}

void Expr::eval(std::vector<Insn> &result)
{
    switch (kind)
    {
    case Add:
        lhs->eval(result);
        rhs->eval(result);
        result.push_back(Insn::ADD);
        break;
    case Sub:
        lhs->eval(result);
        rhs->eval(result);
        result.push_back(Insn::SUB);
        break;
    case Term:
        term->eval(result);
        break;
    case None:
        std::cerr << "Error: Expr kind is None" << std::endl;
        break;
    }
}
void Term::eval(std::vector<Insn> &result)
{
    switch (kind)
    {
    case Mul:
        lhs->eval(result);
        rhs->eval(result);
        result.push_back(Insn::MUL);
        break;
    case Div:
        lhs->eval(result);
        rhs->eval(result);
        result.push_back(Insn::DIV);
        break;
    case Factor:
        factor->eval(result);
        break;
    case None:
        std::cerr << "Error: Expr kind is None" << std::endl;
        break;
    }
}
void Factor::eval(std::vector<Insn> &result)
{
    switch (kind)
    {
    case Number:
        switch (number)
        {
        case 0:
            result.push_back(Insn::INT0);
            break;
        case 1:
            result.push_back(Insn::INT1);
            break;
        case 2:
            result.push_back(Insn::INT2);
            break;
        case 3:
            result.push_back(Insn::INT3);
            break;
        case 4:
            result.push_back(Insn::INT4);
            break;
        case 5:
            result.push_back(Insn::INT5);
            break;
        case 6:
            result.push_back(Insn::INT6);
            break;
        case 7:
            result.push_back(Insn::INT7);
            break;
        case 8:
            result.push_back(Insn::INT8);
            break;
        default:
            std::cerr << "Error: Number out of range" << std::endl;
            exit(1);
        }
        break;
    case Expr:
        expr->eval(result);
        break;
    }
}