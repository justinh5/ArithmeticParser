/*
Author: Justin Haupt
Filename: source.cpp

This file contains functions for the Source class.
The input is obtained through standard input.
*/


#include "source.hpp"


Source::Source(): input(0), position(0) {}

Source::~Source() {
  delete [] input;
  input = NULL;
}

// Reads in a new source of raw characters.
// First deletes the previous set of characters,
// then copies in the new set from user input.
int Source::read_source(char * usr_input) {
  if(input)
      delete [] input;

  input = new char[strlen(usr_input) + 1];
  strcpy(input, usr_input);

  // reset position back to the last character
  position = strlen(input)-1;
  return 1;
}

// Returns the next character from the input buffer,
// starting from index len(input)-1 to 0.
int Source::next_char() {

  if(position >= 0) {
    int next = input[position];
    --position;
    return next;
  }
  return 0;
}
