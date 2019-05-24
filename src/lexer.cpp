
#include "parser.h"


Source::Source(): input(0), position(0) {}

// Reads in a new source of raw characters.
// First deletes the previous set of characters,
// then copies in the new set from user input.
void Source::read_source(char * usr_input) {
  if(input)
      delete [] input;

  input = new char[strlen(usr_input) + 1];
  strcpy(input, usr_input);

  // reset position back to the start and read in the first character
  position = 0;
  end = strlen(input);
  nextChar();

  std::cout << '\n' << input << '\n';
}

int Source::next_char() {

  if(position < end) {
    int next = input[position];
    ++position;
    return next;
  }
  return 0;
}


Lexer::Lexer(Source s): source(s), c(0), lexeme(0), token(0) {}


// Read the input for the next token.
// Can be any one of the enumerated types SUB, ADD, DIV, MUL, EXP, NUM
int Lexer::next_token() {

  while(c == ' ' || c == '\t' || c == '\r') {
    c = source.next_char();
  }

  switch(c) {
    case '-':
      return SUB;
    case '+':
      return ADD;
    case '/':
      return DIV;
    case '*':
      return MUL;
    case '^':
      return EXP;
    case '(':
      return OPEN;
    case ')':
      return CLOSE;
    default:
      return identifier(c);
  }
}


// Identify all digits for the current token.
// Stop reading in characters when a space or ^ is encountered.
int Lexer::identifier(char c) {

  char temp[50];
  strcpy(temp, c);

  c = source.next_char();
  while(c != '^' || c != ' ' || c != '\t' || c != '\r') {
    strcat(temp, c);
    c = source.next_char();
  }

  lexeme = atof(temp);  // char string to double

  return NUM;
}


// Return the current token
Token Lexer::get_token() {
  return token;
}

// Return the current token
double Lexer::get_lexeme() {
  return lexeme;
}
