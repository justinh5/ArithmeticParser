#include "lexer.h"

// Constants

const int MAX_SIZE = 500;  // Maximum input size

// Identifiers for expected input tokens
const int SUB = 45;
const int ADD = 43;
const int DIV = 47;
const int MUL = 42;
const int EXP = 94;
const int OPEN = 40;
const int CLOSE = 41;
const int NUM = 100;



// Reads tokens from the lexer using recursive descent parsing
// to follow the precedence and associativity of the CFG.
class Parser {

  public:
    Parser();
    Parser(Lexer* l);

    Expression* expr();
    Expression* add();
    Expression* div();
    Expression* mul();
    Expression* exp();
    Expression* term();

  private:
    Lexer* lexer;
};
