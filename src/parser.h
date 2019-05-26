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

    double expr();
    double add();
    double div();
    double mul();
    double exp();
    double term();

  private:
    Lexer * lexer;
};




/* If we wanted to build an AST data structure, we could
   declare the following classes:

   class Expression {
     public:
       Expression();
       virtual double evaluate() = 0;
   }

   class Sub: Expression {}
   class Add: Expression {}
   class Div: Expression {}
   class Mul: Expression {}
   class Exp: Expression {}
   class Num: Expression {}


*/
