
#include "lexer.h"
#include "AST.h"

class Parser {

  public:
    Parser(Lexer* l);

    Expression* expr();
    Expression* add();
    Expression* div();
    Expression* mul();
    Expression* exp();
    Expression* atom();

  private:
    Lexer * lexer;
};
