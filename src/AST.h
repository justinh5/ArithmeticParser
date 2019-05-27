#include <iostream>
#include <cstring>
#include <math.h>


// A hierarchy of classes for an AST data structure.
// There is a derived class for each operation, + - * / ^ n
class Expression {

  public:
    Expression();
    virtual~Expression();

    virtual double evaluate() = 0;
};


class Sub: public Expression {

  public:
    Sub();
    ~Sub();
    Sub(Expression* right, Expression* left);

    double evaluate();

  private:
    Expression* a;
    Expression* b;
};


class Add: public Expression {

  public:
    Add();
    ~Add();
    Add(Expression* right, Expression* left);

    double evaluate();

  private:
    Expression* a;
    Expression* b;
};


class Div: public Expression {

  public:
    Div();
    ~Div();
    Div(Expression* right, Expression* left);

    double evaluate();

  private:
    Expression* a;
    Expression* b;
};


class Mul: public Expression {

  public:
    Mul();
    ~Mul();
    Mul(Expression* right, Expression* left);

    double evaluate();

  private:
    Expression* a;
    Expression* b;
};


class Exp: public Expression {

  public:
    Exp();
    ~Exp();
    Exp(Expression* right, Expression* left);

    double evaluate();

  private:
    Expression* base;
    Expression* exponent;
};


class Num: public Expression {

  public:
    Num();
    ~Num();
    Num(double value);

    double evaluate();

  private:
    double n;
};



/*
  If we wanted, we could add functions to print a
  visualization of the AST like this:

  Expression
  |
  + ------------
  |             |
  |             |
  * ----        |
  |     |       |
  |     |       |
  5     6       7

*/
