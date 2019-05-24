#include "parser.h"

const int MAX_SIZE = 500;





int main() {

  char input[MAX_SIZE];
  char result[100];
  Lexer lexar;
  Parser p = Parser(lexar);

  do {

    std::cout << "Type an arithmetic expression to calculate: ";
    std::cin.getline(input, MAX_SIZE);



    std::cout << "result\n";

  } while(strcmp(input, "exit") && strcmp(input, "quit"));



  return 0;
}
