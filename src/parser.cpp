
#include "parser.h"

Parser::Parser(Lexer* l) {
  lexer = l;
}



Expression * Parser::expr() {
  Expression * l = add();
  if (lexer->get_token() == SUB) {
      lexer->next_token();
      return new Sub(l, expr());
  }
  return l;
}

Expression * Parser::add() {
  Expression * l = div();
  if (lexer->get_token() == ADD) {
      lexer->next_token();
      return new Add(l, expr());
  }
  return l;
}

Expression * Parser::div() {
  Expression * l = mul();
  if (lexer->get_token() == DIV) {
      lexer->next_token();
      return new Div(l, expr());
  }
  return l;
}

Expression * Parser::mul() {
  Expression * l = exp();
  if (lexer->get_token() == MUL) {
      lexer->next_token();
      return new Mul(l, expr());
  }
  return l;
}

Expression * Parser::exp() {
  Expression * l = atom();
  if (lexer->get_token() == EXP) {
      lexer->next_token();
      return new Exp(l, expr());
  }
  return l;
}

Expression * Parser::atom() {
  switch (lexer->get_token()) {
    case NUM: {
      double value = lexer->get_lexeme();
      lexer->next_token();
      return new Num(value);
    }
    case OPEN: {
      lexer->next_token();
      Expression * e = expr();
      if (lexer->get_token() == ')') {
        lexer->next_token();
      } else {
        std::cout << "Error! Missing close paren";
      }
      return e;
    }
    default: {
      std::cout << "Error!";
      return NULL;
    }
  }
}
