#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

typedef struct 
{
    int iitem[MAX];  //integer stack
    int itop;        //integer stack's top element
    char citem[MAX]; //char stack
    int ctop;        //char stack's top element
} 
STACK;

// flag shows that if the element that going to push is char or int
void push(int x, char y, STACK *s, int flag) 
{ 
    if (flag == 0) // if it is int 
    {
        s->iitem[s->itop] = x;
        s->itop++;
    } 
    else  //if it is char
    {
        s->citem[s->ctop] = y;
        s->ctop++;
    }
}

//it pops integer element from integer stack
int intPop(STACK *s) 
{ 
    return s->iitem[--s->itop];
}

//it pops char element from char stack
char charPop(STACK *s) 
{
    return s->citem[--s->ctop];
}

//it shows the peek element of the char stack
int peek(STACK *s) 
{ 
    return s->citem[s->ctop - 1];
}

//it makes calculation in order to sign of the operation
int compute(int num1, int num2, char sign) 
{
    if (sign == '+')
        return num1 + num2;
    else if (sign == '-') 
        return num1 - num2;
    else if (sign == '*')
        return num1 * num2;
    else 
        return num1 / num2;
}

//it prints the elements in the stack
void stackPrinter(STACK *s) 
{ 
    printf("OPERAND STACK : ");
    for (int i = 0; i<s->itop; i++) 
    {
        printf("%i ", s->iitem[i]);
    }
    printf("\n");
   
    printf("OPERATOR STACK : ");
    for (int i = 0; i<s->ctop; i++) 
    {
        printf("%c ", s->citem[i]);
    }
    printf("\n");
    
}

//it pushes two number from operand stack and makes calculation
void pushAndCalculate( STACK *s, char sign) 
{ 
    int num2 = intPop(s);
    int num1 = intPop(s);
    push(compute(num1, num2, sign), 0, s, 0);
    stackPrinter(s);
}

//it converts the numbers in char array to integer
int strToInt (char str[]) 
{ 
    int num = 0;
    int i = 0;
    while(i < strlen(str)) {
        num += pow(10, strlen(str)-1-i)*(str[i] - '0');
        i++;
    }
    return num;
}

int main(int argc, char **argv)
{
    char str[MAX], num[MAX], sign;
    int i = 0, j = 0;
    STACK stack;
    stack.itop = 0;
    stack.ctop = 0;
    
    printf("___________ARITHMETIC CALCULATOR__________\n");
    printf("Insert the operation that you want to calculate : ");
    scanf("%[^\n]s ", str);
    
    // string tokenizer
    while(i < strlen(str)) 
    {
        if ((str[i]>='0') && (str[i]<='9')) 
        { 
            while ( (str[i]>='0') && (str[i]<='9') ) 
            { 
                num[j] = str[i]; 
                i++; 
                j++;
            }
            num[j] = '\0';
            push(strToInt(num), 0, &stack, 0);
            stackPrinter(&stack);
            j = 0;
            num[0] = '\0';
        }
        else if (str[i] == ' ') 
        {
            i++;
        }
        else if ( str[i] == ')') 
        {
            sign = charPop(&stack);
            stackPrinter(&stack);
            // it push values until '(' sign comes
            while (sign != '(') 
            { 
                pushAndCalculate(&stack, sign);
                sign = charPop(&stack);
                stackPrinter(&stack);
            }
            i++;
        }
        else if (str[i] == '(') 
        {
            push(0 ,str[i], &stack, 1);
            stackPrinter(&stack);
            i++;
        }
        else if ( (str[i] == '*') || (str[i] == '/') ) 
        {
            if ( (peek(&stack) == '*') || (peek(&stack) == '/') ) 
            { // priority operator control
                sign = charPop(&stack);
                stackPrinter(&stack);
                pushAndCalculate(&stack, sign);
            }
            push(0, str[i], &stack, 1);
            stackPrinter(&stack);
            i++;
        }
        else if ( (str[i] == '+') || (str[i] == '-') ) 
        {
            if ( (peek(&stack) == '*') || (peek(&stack) == '/') || (peek(&stack) == '+') || (peek(&stack) == '-')) 
            { //priority operand control
                sign = charPop(&stack);
                stackPrinter(&stack);
                pushAndCalculate(&stack, sign);
            }
            push(0, str[i], &stack, 1);
            stackPrinter(&stack);
            i++;
        }
    }
    
    while(peek(&stack)) 
    { //after the string reading the elements remaining elements from stack pops
        sign = charPop(&stack);
        stackPrinter(&stack);
        pushAndCalculate(&stack, sign);
    }
    printf("Operation result : %d \n", stack.iitem[0]);
}
