## Arithmetic Parser

A simple parser for arithmetic expressions. Evaluates expressions from the command line given a string of characters (eg. "1-2+3*4/5").

There are three main components:

Source -> Lexer -> Parser

**Source** - Manages the input buffer of characters.
<br>**Lexer** - Reads in characters from the source and outputs tokens. Tokens are read from right to left to maintain a left grouping. White space is skipped.
<br>**Parser** - Reads tokens from the lexer using recursive descent parsing to follow the precedence and associativity of the CFG. It produces an AST data structure, where the expression it represents can then be evaluated.


## Context-free Grammar

The following CFG describes all possible arithmetic strings that can be parsed. It uses PEMDAS order of operations and associates to the left. For an example, a chain of minus operations would be evaluated like (((((9-8)-7)-6)-5)).

Expression -> Expression - Add
<br>Expression -> Add

Add -> Add + Div
<br>Add -> Div

Div -> Div / Mul
<br>Div -> Mul

Mul -> Mul * Exp
<br>Mul -> Exp

Exp -> Exp ^ Term
<br>Exp -> Term

Term -> (Expression)
<br>Term -> n

## Examples

Each of the following are valid input strings:

9
<br>9 + 9
<br>9+9
<br>9.33 - 10.44
<br>6 - 3 - 2
<br>(7*8) / (2-1)
<br>5^8
<br>(4/6+8)^(2^2)
<br>(4-(6/2+1)-2-(3)+9+(4*5-6))
