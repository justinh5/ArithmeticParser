/*
Author: Justin Haupt
Filename: lexer.cpp

This file contains functions for the Lexer class.
There are functions for reading the next token from the source,
getting the current token or lexeme, and identifying lexemes.

TODO: Identify garbage input and return with an error.
*/


#include "parser.hpp"


// Default constructor
Lexer::Lexer(): source(0), c(0), lexeme(0), token(0) {}

Lexer::Lexer(Source* s): c(0), lexeme(0), token(0) {
  source = s;
}

// Read in the first character and token before parsing
void Lexer::start() {
  c = source->next_char();
  token = next_token();
}

// Read the input for the next token
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
int Lexer::identify() {

  int i = 0;
  char temp[50];

  while((c > 47 && c < 58) || c == 46) {   // append characters unit a non-digit is read
    temp[i] = c;
    c = source->next_char();
    ++i;
  }
  temp[i] = '\0';                           // insert null terminator
  std::reverse(temp, &temp[strlen(temp)]);  // reverse characters in temp
  lexeme = atof(temp);                      // char string to double

  return NUM;
}

// Return the current token
int Lexer::get_token() {
  return token;
}

// Return the current lexeme
double Lexer::get_lexeme() {
  return lexeme;
}
