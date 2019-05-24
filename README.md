## Arithmetic Parser

A simple parser for arithmetic expressions.

Source Input -> Lexer -> Parser


###Context-free Grammar

The CFG Follows PEMDAS order of operations and groups to the left, avoiding ambiguity.

E -> E - G
E -> G

G -> G + H
G -> H

J -> J / K
J -> K

K -> K * M
K -> M

M -> M ^ A
M -> A

A -> (E)
A -> n
