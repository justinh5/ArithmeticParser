
#include "lexer.h"

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
