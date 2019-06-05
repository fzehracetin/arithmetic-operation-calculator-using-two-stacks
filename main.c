#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

typedef struct {
    int iitem[MAX];  //integer stackin eleman dizisi
    int itop;        //integer stackin en ustteki elemani
    char citem[MAX]; // char stackin eleman dizisi
    int ctop;        //char stackin en ustteki elemani
} STACK;

void push(int x, char y, STACK *s, int flag) { // flag push edilecek degerin char ya da int olma durumunu gosterir
    if (flag == 0) {
        s->iitem[s->itop] = x;
        s->itop++;
    } 
    else {
        s->citem[s->ctop] = y;
        s->ctop++;
    }
}

int intPop(STACK *s) { // integer deger pop eder
    s->itop--;
    return s->iitem[s->itop];
}

char charPop(STACK *s) { // char deger pop eder
    s->ctop--;
    return s->citem[s->ctop];
}

int peek(STACK *s) { // stackte en ustteki degeri gosterir
    return s->citem[s->ctop - 1]; // yalnizca char icin yazildi
}
int compute(int num1, int num2, char sign) { //isaret karakterine gore islemi yapar
    if (sign == '+')
        return num1 + num2;
    else if (sign == '-') 
        return num1 - num2;
    else if (sign == '*')
        return num1 * num2;
    else 
        return num1 / num2;
}

void stackPrinter(STACK *s) { // stack yazdirir
    printf("NUMBER STACK : ");
    for (int i = 0; i<s->itop; i++) {
        printf("%i ", s->iitem[i]);
    }
    printf("\n");
    printf("SIGN STACK : ");
    for (int i = 0; i<s->ctop; i++) {
        printf("%c ", s->citem[i]);
    }
    printf("\n");
    
}

void pushAndCalculate( STACK *s, char sign) { // sayi stackinden iki deger ceker ve islem yapar
    int num2 = intPop(s);
    int num1 = intPop(s);
    push(compute(num1, num2, sign), 0, s, 0);
    stackPrinter(s);
}

int strToInt (char str[]) { // string icindeki sayilarin decimal karsiligini alir
    int num = 0;
    int i = 0;
    while(i < strlen(str)) {
        num += pow(10, strlen(str)-1-i)*(str[i] - '0'); // basamak degerleri ile carpilir
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
    
    printf("___________ARITMETIK HESAPLAYICI__________\n");
    printf("Yapmak istediginiz islemi giriniz : ");
    scanf("%[^\n]s ", str);
    
    while(i < strlen(str)) {
        if ((str[i]>='0') && (str[i]<='9')) { // sayi okumasi durumu
            while ( (str[i]>='0') && (str[i]<='9') ) { // sayinin birden fazla basamak olmasi durumu icin
                num[j] = str[i]; // num dizisinde char halinde sayilar durur
                i++; j++;
            }
            num[j] = '\0';
            push(strToInt(num), 0, &stack, 0); // char halindeki sayilar integera cevrilir ve push edilir
            stackPrinter(&stack);
            j = 0;
            num[0] = '\0';
        }
        else if (str[i] == ' ') {
            i++;
        }
        else if ( str[i] == ')') {
            sign = charPop(&stack);
            stackPrinter(&stack);
            while (sign != '(') { // '(' gorulene kadar push eder ve islem yapar
                pushAndCalculate(&stack, sign);
                sign = charPop(&stack);
                stackPrinter(&stack);
            }
            i++;
        }
        else if (str[i] == '(') {
            push(0 ,str[i], &stack, 1);
            stackPrinter(&stack);
            i++;
        }
        else if ( (str[i] == '*') || (str[i] == '/') ) {
            if ( (peek(&stack) == '*') || (peek(&stack) == '/') ) { // daha buyuk isaretli bir sey varsa stackten pop edilir ve islem yapilir
                sign = charPop(&stack);
                stackPrinter(&stack);
                pushAndCalculate(&stack, sign);
            }
            push(0, str[i], &stack, 1);
            stackPrinter(&stack);
            i++;
        }
        else if ( (str[i] == '+') || (str[i] == '-') ) {
            if ( (peek(&stack) == '*') || (peek(&stack) == '/') || (peek(&stack) == '+') || (peek(&stack) == '-')) { //buyuk isaret kontrolu
                sign = charPop(&stack);
                stackPrinter(&stack);
                pushAndCalculate(&stack, sign);
            }
            push(0, str[i], &stack, 1);
            stackPrinter(&stack);
            i++;
        }
    }
    
    while(peek(&stack)) { //string okumasi bittikten sonra stackte kalanlar cekilir ve islem yapilir
        sign = charPop(&stack);
        stackPrinter(&stack);
        pushAndCalculate(&stack, sign);
    }
    printf("Islem sonucu : %d \n", stack.iitem[0]);
}
