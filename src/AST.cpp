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
