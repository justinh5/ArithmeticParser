



class Expression {

  public:
    Expression();

  private:


};


class SUB: Expression {

  public:
    SUB();

  private:
    Expression a;
    Expression b;
};


class ADD: Expression {

  public:
    ADD();

  private:
    Expression a;
    Expression b;
};


class DIV: Expression {

  public:
    DIV();

  private:
    Expression a;
    Expression b;
};


class MUL: Expression {

  public:
    MUL();

  private:
    Expression a;
    Expression b;
};


class EXP: Expression {

  public:
    EXP();

  private:
    Expression a;
    Expression b;
};
