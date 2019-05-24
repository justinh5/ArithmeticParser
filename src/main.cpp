#include "parser.h"

const int MAX_SIZE = 500;





int main() {

  char * input = new char[MAX_SIZE];

  do {

    std::cout << "Type an arithmetic expression to calculate: ";
    std::cin.getline(input, MAX_SIZE);


  } while(strcmp(input, "exit") && strcmp(input, "quit"));



  return 0;
}
