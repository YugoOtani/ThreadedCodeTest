
// Generated from Expr.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "ExprParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by ExprParser.
 */
class  ExprListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterAdd(ExprParser::AddContext *ctx) = 0;
  virtual void exitAdd(ExprParser::AddContext *ctx) = 0;

  virtual void enterSub(ExprParser::SubContext *ctx) = 0;
  virtual void exitSub(ExprParser::SubContext *ctx) = 0;

  virtual void enterExpTerm(ExprParser::ExpTermContext *ctx) = 0;
  virtual void exitExpTerm(ExprParser::ExpTermContext *ctx) = 0;

  virtual void enterDiv(ExprParser::DivContext *ctx) = 0;
  virtual void exitDiv(ExprParser::DivContext *ctx) = 0;

  virtual void enterTermFactor(ExprParser::TermFactorContext *ctx) = 0;
  virtual void exitTermFactor(ExprParser::TermFactorContext *ctx) = 0;

  virtual void enterMul(ExprParser::MulContext *ctx) = 0;
  virtual void exitMul(ExprParser::MulContext *ctx) = 0;

  virtual void enterNumber(ExprParser::NumberContext *ctx) = 0;
  virtual void exitNumber(ExprParser::NumberContext *ctx) = 0;

  virtual void enterFactorExpr(ExprParser::FactorExprContext *ctx) = 0;
  virtual void exitFactorExpr(ExprParser::FactorExprContext *ctx) = 0;


};

