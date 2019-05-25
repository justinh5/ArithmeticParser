
#include "parser.h"

Parser::Parser(Lexer* l) {
  lexer = l;
}

double Parser::expr() {
  double l = add();
  if (lexer->get_token() == SUB) {
    lexer->next_token();
    return expr() - l;
  }
  return l;
}

double Parser::add() {
  double l = div();
  if (lexer->get_token() == ADD) {
    lexer->next_token();
    return expr() + l;
  }
  return l;
}

double Parser::div() {
  double l = mul();
  if (lexer->get_token() == DIV) {
    lexer->next_token();
    return expr() / l;
  }
  return l;
}

double Parser::mul() {
  double l = exp();
  if (lexer->get_token() == MUL) {
    lexer->next_token();
    return expr() * l;
  }
  return l;
}

double Parser::exp() {
  double l = term();
  if (lexer->get_token() == EXP) {
    lexer->next_token();
    return pow(expr(), l);
  }
  return l;
}

double Parser::term() {
  switch (lexer->get_token()) {
    case NUM: {
      double value = lexer->get_lexeme();
      lexer->next_token();
      return value;
    }
    case CLOSE: {
      lexer->next_token();
      double e = expr();
      if (lexer->get_token() == '(') {
        lexer->next_token();
      } else {
        std::cout << "Error! Missing open paren";
      }
      return e;
    }
    default: {
      std::cout << "Error!";
      return 0;
    }
  }
}
