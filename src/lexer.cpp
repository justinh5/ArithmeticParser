
#include "parser.h"


Source::Source(): input(0), position(0) {}


Source::Source(const Source& s) {
  input = new char[strlen(s.input) + 1];
  position = 0;
  end = 0;
}

Source::~Source() {
  delete [] input;
  input = NULL;
}


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
}

int Source::next_char() {

  if(position < end) {
    int next = input[position];
    ++position;
    return next;
  }
  return 0;
}

Lexer::Lexer(): source(0), c(0), lexeme(0), token(0) {}

Lexer::Lexer(Source* s): c(0), lexeme(0), token(0) {
  source = s;
}

Lexer::Lexer(const Lexer& l) {
  source = l.source;
  c = lexeme = token = 0;
}

void Lexer::start() {
  c = source->next_char();
  token = next_token();
}


// Read the input for the next token.
// Can be any one of the enumerated types SUB, ADD, DIV, MUL, EXP, NUM
int Lexer::next_token() {

  while(c == ' ' || c == '\t' || c == '\r') {
    c = source->next_char();
  }

  switch(c) {
    case '-':
      c = source->next_char();
      return token=SUB;
    case '+':
      c = source->next_char();
      return token=ADD;
    case '/':
      c = source->next_char();
      return token=DIV;
    case '*':
      c = source->next_char();
      return token=MUL;
    case '^':
      c = source->next_char();
      return token=EXP;
    case '(':
      c = source->next_char();
      return token=OPEN;
    case ')':
      c = source->next_char();
      return token=CLOSE;
    default:
      return token=identify();
  }
}


// Identify all digits for the current token.
// Stop reading in characters when a space or ^ is encountered.
int Lexer::identify() {

  int i = 0;
  char temp[50];

  while((c > 47 && c < 58) || c == 46) {
    temp[i] = c;
    c = source->next_char();
    ++i;
  }

  lexeme = atof(temp);  // char string to double

  return NUM;
}


// Return the current token
int Lexer::get_token() {
  return token;
}

// Return the current token
double Lexer::get_lexeme() {
  return lexeme;
}
