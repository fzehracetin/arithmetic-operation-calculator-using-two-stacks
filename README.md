# Arithmetic Operation Calculator Using Two Stack

**Calculate an arithmetic operation using operand and operator stacks. Arithmetic operation is given in string format.**

When we read the input string char by char if the character is a number it must push into Operand Stack. If the character is an operator we must follow these:

1. If the character is '(' push it into Operator Stack.

2. If the character is ')' pop the operators from Operator Stack untill '(' character. For every operator pop two number from Operand Stack after the calculation between operands and the operator, the result must push into Operator Stack.

3. If the character is one of these '-', '+', 'x', '/' look at the sign hierarchy between new character and the peek of the Operator Stack. If the new sign in lower class in hierarchy pop the signs from Operator Stack that have upper class. For all pop process from Operator Stack pop two number from Operand Stack and make calculation. Result must push into Operand Stack. If the new sign in upper class or equivalent with the peek of the Operator Stack, push the new sign to the Operator Stack. 

After all reading process we must pop remaining things in two stacks and we must do calculation between them. When the Operator Stack turn into empty the only number in the Operand Stack is the result of the arithmetic operation.

### Sign Hierarcy
(upper to lower)

   **(**

   **x /**

   **+ -**

### Example :

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
