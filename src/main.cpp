#include "parser.h"






int main() {

  char input[MAX_SIZE];
  Source source;
  Lexer lexer = Lexer(source);
  Parser parser = Parser(lexer);

  do {

    std::cout << "Type an arithmetic expression to calculate: ";
    std::cin.getline(input, MAX_SIZE);
    source.read_source(input);         // feed new input to the source
    Expression * e = parser.expr();    // parse expression to AST
    std::cout << '\n' << e->evaluate() << '\n';

  } while(strcmp(input, "exit") && strcmp(input, "quit"));



  return 0;
}
