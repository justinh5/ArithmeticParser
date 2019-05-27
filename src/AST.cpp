#include "AST.h"


Expression::Expression() {}
Sub::Sub() {}
Add::Add() {}
Div::Div() {}
Mul::Mul() {}
Exp::Exp() {}
Num::Num() {}

Sub::Sub(Expression* right, Expression* left): a(right), b(left) {}
Add::Add(Expression* right, Expression* left): a(right), b(left) {}
Div::Div(Expression* right, Expression* left): a(right), b(left) {}
Mul::Mul(Expression* right, Expression* left): a(right), b(left) {}
Exp::Exp(Expression* right, Expression* left): base(right), exponent(left) {}
Num::Num(double value): n(value) {}

// Destructors
Expression::~Expression() {}

Sub::~Sub() {
  delete a;
  delete b;
}

Add::~Add() {
  delete a;
  delete b;
}

Div::~Div() {
  delete a;
  delete b;
}

Mul::~Mul() {
  delete a;
  delete b;
}

Exp::~Exp() {
  delete base;
  delete exponent;
}

Num::~Num() {}

double Sub::evaluate() {
  return a->evaluate() - b->evaluate();
}

double Add::evaluate() {
  return a->evaluate() + b->evaluate();
}

double Div::evaluate() {
  return a->evaluate() / b->evaluate();
}

double Mul::evaluate() {
  return a->evaluate() * b->evaluate();
}

double Exp::evaluate() {
  return pow(base->evaluate(), exponent->evaluate());
}

double Num::evaluate() {
  return n;
}
