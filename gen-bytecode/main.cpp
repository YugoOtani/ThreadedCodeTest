#include <iostream>
#include <vector>
#include "antlr4-runtime.h"
#include "parser/ExprLexer.h"
#include "parser/ExprParser.h"
#include "parser/ExprBaseListener.h"
#include "ast.h"

using namespace antlr4;

std::string input_path = "../bytecode/input.txt";
std::string output_path = "../bytecode/bytecode.txt";
std::string debugfile_path = "../bytecode/debug.txt";
std::unique_ptr<Term> visitTerm(ExprParser::TermContext *ctx);
std::unique_ptr<Factor> visitFactor(ExprParser::FactorContext *ctx);

std::unique_ptr<Expr> visitExpr(ExprParser::ExprContext *ctx)
{
    if (auto div = dynamic_cast<ExprParser::AddContext *>(ctx))
    {
        return Expr::createAdd(visitExpr(div->expr()), visitTerm(div->term()));
    }
    else if (auto mul = dynamic_cast<ExprParser::SubContext *>(ctx))
    {
        return Expr::createSub(visitExpr(mul->expr()), visitTerm(mul->term()));
    }
    else if (auto exp_term = dynamic_cast<ExprParser::ExpTermContext *>(ctx))
    {
        return Expr::createTerm(visitTerm(exp_term->term()));
    }
    return nullptr;
}
std::unique_ptr<Term> visitTerm(ExprParser::TermContext *ctx)
{
    if (auto add = dynamic_cast<ExprParser::MulContext *>(ctx))
    {
        return Term::createMul(visitTerm(add->term()), visitFactor(add->factor()));
    }
    else if (auto sub = dynamic_cast<ExprParser::DivContext *>(ctx))
    {
        return Term::createDiv(visitTerm(sub->term()), visitFactor(sub->factor()));
    }
    else if (auto term_factor = dynamic_cast<ExprParser::TermFactorContext *>(ctx))
    {
        return Term::createFactor(visitFactor(term_factor->factor()));
    }
    return nullptr;
}
std::unique_ptr<Factor> visitFactor(ExprParser::FactorContext *ctx)
{
    if (auto number = dynamic_cast<ExprParser::NumberContext *>(ctx))
    {
        return Factor::createNumber(std::stoi(number->INT()->getText()));
    }
    else if (auto factor_expr = dynamic_cast<ExprParser::FactorExprContext *>(ctx))
    {
        return Factor::createExpr(visitExpr(factor_expr->expr()));
    }
    return nullptr;
}

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

    std::string input, line;
    while (std::getline(infile, line))
        input.append(line + "\n");
    infile.close();
    ANTLRInputStream inputStream(input);

    ExprLexer lexer(&inputStream);
    CommonTokenStream tokens(&lexer);
    ExprParser parser(&tokens);

    auto ctx = parser.expr();
    auto ast = visitExpr(ctx);
    auto insns = std::vector<Insn>();

    ast->eval(insns);
    insns.push_back(Insn::RETURN);
    std::ofstream outfile(output_path);
    std::ofstream debugfile(debugfile_path);
    for (auto insn : insns)
    {
        outfile << (int)insn << std::endl;
        debugfile << (int)insn;
        switch (insn)
        {
        case Insn::ADD:
            debugfile << "; ADD\n";
            break;
        case Insn::SUB:
            debugfile << "; SUB\n";
            break;
        case Insn::MUL:
            debugfile << "; MUL\n";
            break;
        case Insn::DIV:
            debugfile << "; DIV\n";
            break;
        case Insn::RETURN:
            debugfile << "; RETURN\n";
            break;
        case Insn::INT0:
            debugfile << "; INT0\n";
            break;
        case Insn::INT1:
            debugfile << "; INT1\n";
            break;
        case Insn::INT2:
            debugfile << "; INT2\n";
            break;
        case Insn::INT3:
            debugfile << "; INT3\n";
            break;
        case Insn::INT4:
            debugfile << "; INT4\n";
            break;
        case Insn::INT5:
            debugfile << "; INT5\n";
            break;
        case Insn::INT6:
            debugfile << "; INT6\n";
            break;
        case Insn::INT7:
            debugfile << "; INT7\n";
            break;
        case Insn::INT8:
            debugfile << "; INT8\n";
            break;
        case Insn::NOP:
            debugfile << "; NOP\n";
            break;
        }
    }
}
