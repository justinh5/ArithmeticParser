#include <iostream>
#include <cstring>
#include <math.h>

const int MAX_SIZE = 500;

const int SUB = 45;
const int ADD = 43;
const int DIV = 47;
const int MUL = 42;
const int EXP = 94;
const int OPEN = 40;
const int CLOSE = 41;
const int NUM = 100;



class Source {

  public:
    Source();
    Source(const Source& s);
    ~Source();

    void read_source(char * input);
    int next_char();


  private:
    char * input;       // source input
    int position;       // current position in the input array
};




class Lexer {

  public:
    Lexer();
    Lexer(Source* s);
    Lexer(const Lexer& l);   // copy constructor

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
