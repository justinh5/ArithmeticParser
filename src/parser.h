
#include "lexer.h"
#include "AST.h"

class Parser
{

  public:
    Parser(Lexer l);

  private:
    Lexer lexer;
};
