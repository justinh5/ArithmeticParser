#include "source.h"




Source::Source(): input(0), position(0) {}

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

  // reset position back to the last character
  position = strlen(input)-1;
}

int Source::next_char() {

  if(position >= 0) {
    int next = input[position];
    --position;
    return next;
  }
  return 0;
}
