



class Expression
{

  public:
    Expression();

    virtual ~Expression();
    virtual double evaluate() = 0;

  private:


};


class SUB: public Expression
{

  public:
    SUB();
    double evaluate();

  private:
    Expression a;
    Expression b;
};


class ADD: public Expression
{

  public:
    ADD();
    double evaluate();

  private:
    Expression a;
    Expression b;
};


class DIV: public Expression
{

  public:
    DIV();
    double evaluate();

  private:
    Expression a;
    Expression b;
};


class MUL: public Expression {

  public:
    MUL();
    double evaluate();

  private:
    Expression a;
    Expression b;
};


class EXP: public Expression
{

  public:
    EXP();
    double evaluate();

  private:
    Expression base;
    Expression exponent;
};


class NUM: public Expression
{

  public:
    NUM();
    double evaluate();

  private:
    double n;
};
