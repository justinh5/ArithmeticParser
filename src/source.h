#include "AST.h"


// Holds the source string of user input and
// provides the next character in the buffer for the lexer.
class Source {

  public:
    Source();
    ~Source();

    void read_source(char* input);
    int next_char();

  private:
    char* input;    // source input
    int position;    // current position in the input array
};
