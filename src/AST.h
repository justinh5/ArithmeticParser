



class Expression {

  public:
    Expression();

  private:


};


class SUB: public Expression {

  public:
    SUB();

  private:
    Expression a;
    Expression b;
};


class ADD: public Expression {

  public:
    ADD();

  private:
    Expression a;
    Expression b;
};


class DIV: public Expression {

  public:
    DIV();

  private:
    Expression a;
    Expression b;
};


class MUL: public Expression {

  public:
    MUL();

  private:
    Expression a;
    Expression b;
};


class EXP: public Expression {

  public:
    EXP();

  private:
    Expression base;
    Expression exponent;
};


class NUM: public Expression {

  public:
    NUM();

  private:
    double n;
};
