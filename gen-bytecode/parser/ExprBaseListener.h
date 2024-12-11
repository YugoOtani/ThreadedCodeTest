
// Generated from Expr.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "ExprListener.h"


/**
 * This class provides an empty implementation of ExprListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  ExprBaseListener : public ExprListener {
public:

  virtual void enterAdd(ExprParser::AddContext * /*ctx*/) override { }
  virtual void exitAdd(ExprParser::AddContext * /*ctx*/) override { }

  virtual void enterSub(ExprParser::SubContext * /*ctx*/) override { }
  virtual void exitSub(ExprParser::SubContext * /*ctx*/) override { }

  virtual void enterExpTerm(ExprParser::ExpTermContext * /*ctx*/) override { }
  virtual void exitExpTerm(ExprParser::ExpTermContext * /*ctx*/) override { }

  virtual void enterDiv(ExprParser::DivContext * /*ctx*/) override { }
  virtual void exitDiv(ExprParser::DivContext * /*ctx*/) override { }

  virtual void enterTermFactor(ExprParser::TermFactorContext * /*ctx*/) override { }
  virtual void exitTermFactor(ExprParser::TermFactorContext * /*ctx*/) override { }

  virtual void enterMul(ExprParser::MulContext * /*ctx*/) override { }
  virtual void exitMul(ExprParser::MulContext * /*ctx*/) override { }

  virtual void enterNumber(ExprParser::NumberContext * /*ctx*/) override { }
  virtual void exitNumber(ExprParser::NumberContext * /*ctx*/) override { }

  virtual void enterFactorExpr(ExprParser::FactorExprContext * /*ctx*/) override { }
  virtual void exitFactorExpr(ExprParser::FactorExprContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

