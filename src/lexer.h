#include "source.h"





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
