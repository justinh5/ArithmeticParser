#include "lexer.h"

// Constants
const int MAX_SIZE = 500;

const int SUB = 45;
const int ADD = 43;
const int DIV = 47;
const int MUL = 42;
const int EXP = 94;
const int OPEN = 40;
const int CLOSE = 41;
const int NUM = 100;


class Parser {

  public:
    Parser(Lexer* l);

    double expr();
    double add();
    double div();
    double mul();
    double exp();
    double term();

  private:
    Lexer * lexer;
};
