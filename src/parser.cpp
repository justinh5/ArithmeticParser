/*
Author: Justin Haupt
Filename: parser.cpp

This file contains functions for the Parser class.
The functions are recursively descending to match the
grammar, and each one returns an Expression ADT.
*/


#include "parser.h"


Parser::Parser(): lexer(0) {}

Parser::Parser(Lexer* l) {
  lexer = l;
}

Expression* Parser::expr() {
  Expression* l = add();
  if (lexer->get_token() == SUB) {
    lexer->next_token();
    return new Sub(expr(), l);
  }
  return l;
}

Expression* Parser::add() {
  Expression* l = div();
  if (lexer->get_token() == ADD) {
    lexer->next_token();
    return new Add(add(), l);
  }
  return l;
}

Expression* Parser::div() {
  Expression* l = mul();
  if (lexer->get_token() == DIV) {
    lexer->next_token();
    return new Div(div(), l);
  }
  return l;
}

Expression* Parser::mul() {
  Expression* l = exp();
  if (lexer->get_token() == MUL) {
    lexer->next_token();
    return new Mul(mul(), l);
  }
  return l;
}

Expression* Parser::exp() {
  Expression* l = term();
  if (lexer->get_token() == EXP) {
    lexer->next_token();
    return new Exp(exp(), l);
  }
  return l;
}

Expression* Parser::term() {
  switch (lexer->get_token()) {
    case NUM: {
      double value = lexer->get_lexeme();
      lexer->next_token();
      return new Num(value);
    }
    case CLOSE: {
      lexer->next_token();
      Expression* e = expr();
      if (lexer->get_token() == '(') {
        lexer->next_token();
      } else {
        std::cout << "Error! Missing open paren";
        return 0;
      }
      return e;
    }
    default: {
      std::cout << "Error!";
      return 0;
    }
  }
}
