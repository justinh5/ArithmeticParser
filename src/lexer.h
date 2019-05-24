#include <iostream>
#include <cstring>



enum Token { START, SUB, ADD, DIV, MUL, EXP, NUM };




class Lexer {

  public:
    Lexer();

    void source(char * input);
    Token getToken();
    void nextToken();

  private:
    char * input;
    Token token;
};
