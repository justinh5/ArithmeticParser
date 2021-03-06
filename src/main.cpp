/*
Author: Justin Haupt
Filename: main.cpp

This is the main file, containing the client program.
The user inputs expression strings to the command line, then they are
sent to the Source ADT. The input is analyzed, parsed, and the evaluated
expression is then output.
*/


#include "parser.hpp"


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
    exit = strcmp(input, "exit") && strcmp(input, "quit");
    if(exit) {
      lexer.start();    // read in first char and token
      Expression* e = parser.expr();
      std::cout << "= " << e->evaluate() << "\n\n";
      delete e;
    }
  } while(exit);

  return 0;
}
