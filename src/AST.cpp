
#include "AST.h"


Expression::Expression() {}

Expression::~Expression() {}

Sub::Sub(Expression * left, Expression * right) {
  a = left;
  b = right;
}

double Sub::evaluate() {
  return a->evaluate() - b->evaluate();
}

Add::Add(Expression * left, Expression * right) {
  a = left;
  b = right;
}

double Add::evaluate() {
  return a->evaluate() + b->evaluate();
}

Div::Div(Expression * left, Expression * right) {
  a = left;
  b = right;
}

double Div::evaluate() {
  return a->evaluate() / b->evaluate();
}

Mul::Mul(Expression * left, Expression * right) {
  a = left;
  b = right;
}

double Mul::evaluate() {
  return a->evaluate() * b->evaluate();
}

Exp::Exp(Expression * left, Expression * right) {
  base = left;
  exponent = right;
}

double Exp::evaluate() {
  return pow(base->evaluate(), exponent->evaluate());
}

Num::Num(double value) {
  n = value;
}

double Num::evaluate() {
  return n;
}
