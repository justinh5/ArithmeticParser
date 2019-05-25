#include "parser.h"






int main() {

  char input[MAX_SIZE];
  Source source;
  Lexer lexer = Lexer(&source);
  Parser parser = Parser(&lexer);
  bool exit = 1;

  do {
    std::cout << "Type an arithmetic expression to calculate: ";
    std::cin.getline(input, MAX_SIZE);
    source.read_source(input);    // feed new input to the source
    exit = strcmp(input, "exit") && strcmp(input, "quit");  // time to exit?
    if(exit) {
      lexer.start();    // read in first char and token
      std::cout << "= " << parser.expr() << "\n\n";
    }
  } while(exit);

  return 0;
}
