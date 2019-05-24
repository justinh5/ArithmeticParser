#include "parser.h"

const int MAX_SIZE = 500;





int main() {

  char input[MAX_SIZE];
  Lexer lexer;
  Parser p = Parser(lexer);

  do {

    std::cout << "Type an arithmetic expression to calculate: ";
    std::cin.getline(input, MAX_SIZE);
    lexer.source(input);        // feed new source to the lexer
    // Expression e = p.expr();    // parse expression to AST
    // std::cout << '\n' << e.evaluate() << '\n';

  } while(strcmp(input, "exit") && strcmp(input, "quit"));



  return 0;
}
