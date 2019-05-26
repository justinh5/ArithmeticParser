#include "source.h"


// A lexical analyzer that reads in characters from the
// source and identifies lexemes and tokens.
// Tokens have distince integer values that are listed in parser.h.
// Lexemes are identified as strings of digits(type double). So
// the following can be stored as lexemes: (3, 35, 3.5)
class Lexer {

  public:
    Lexer();
    Lexer(Source* s);

    void start();
    int get_token();
    double get_lexeme();
    int next_token();
    int identify();

  private:
    Source * source;
    char c;             // current character
    double lexeme;      // the value of a term in the expression (float or int)
    int token;          // the current token
};
