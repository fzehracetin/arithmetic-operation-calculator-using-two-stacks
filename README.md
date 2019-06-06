# Arithmetic Operation Calculator Using Two Stack

Calculate an arithmetic operation using operand and operator stacks. Arithmetic operation is given in string format.


**Example :** 

**Input :** 12 * (4 + 3 - 16 / 8) – 5

**Operand Stack :** 12

**Operator Stack :** Empty

**Operand Stack :** 12

**Operator Stack :** *

**Operand Stack :** 12

**Operator Stack :** * (

**Operand Stack :** 12 4

**Operator Stack :** * (

**Operand Stack :** 12 4

**Operator Stack :** * ( +

**Operand Stack :** 12 4 3

**Operator Stack :** * ( +

**Operand Stack :** 12 7

**Operator Stack :** * ( -

**Operand Stack :** 12 7 16

**Operator Stack :** * ( -

**Operand Stack :** 12 7 16

**Operator Stack :** * ( - /

**Operand Stack :** 12 7 16 8

**Operator Stack :** * ( - /

**Operand Stack :** 12 7 2

**Operator Stack :** * ( -

**Operand Stack :** 12 5

**Operator Stack :** *

**Operand Stack :** 60

**Operator Stack :** -

**Operand Stack :** 60 5

**Operator Stack :** -

**RESULT :** 60-5 = 55
