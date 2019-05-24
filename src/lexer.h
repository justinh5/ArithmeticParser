#include <iostream>
#include <cstring>


/*

1  -
2  +
3  /
4  *
5  ^


*/

class Token
{
  public:
    Token();

  private:
    int value;


};


class Lexer
{

  public:
    Lexer();

  private:
    Token token;
};
