
#include <math.h>


class Expression {

  public:
    Expression();
    virtual ~Expression();

    virtual double evaluate() = 0;

  private:


};


class Sub: public Expression {

  public:
    Sub(Expression * left, Expression * right);

    double evaluate();

  private:
    Expression * a;
    Expression * b;
};


class Add: public Expression {

  public:
    Add(Expression * left, Expression * right);

    double evaluate();

  private:
    Expression * a;
    Expression * b;
};


class Div: public Expression {

  public:
    Div(Expression * left, Expression * right);

    double evaluate();

  private:
    Expression * a;
    Expression * b;
};


class Mul: public Expression {

  public:
    Mul(Expression * left, Expression * right);

    double evaluate();

  private:
    Expression * a;
    Expression * b;
};


class Exp: public Expression {

  public:
    Exp(Expression * left, Expression * right);

    double evaluate();

  private:
    Expression * base;
    Expression * exponent;
};


class Num: public Expression {

  public:
    Num(double value);

    double evaluate();

  private:
    double n;
};
