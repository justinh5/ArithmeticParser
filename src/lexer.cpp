
#include "parser.h"


Lexer::Lexer(): input(0), token(START) {}


// Reads in a new source of raw characters.
// First deletes the previous set of characters,
// then copies in the new set from user input.
void Lexer::source(char * usr_input) {
  if(input)
      delete [] input;

  input = new char[strlen(usr_input) + 1];
  strcpy(input, usr_input);

  std::cout << '\n' << input << '\n';

}
