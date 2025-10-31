#include <stdio.h>
#include "Calc.c"

//For Initial Purpose,We are taking type of operation and values separately (May Change Later)



void main()
{
    float value1,value2;
    char operant;
    double result;
    char opt;


    printf("Enter Value 1 and 2(Second Value can be zero for square,square root and reciprocal):- \n");
    scanf("%f %f",&value1,&value2);
    printf("Enter Operant(+,-,*,/,^(square),?(square root),~(reciprocal)):- \n");
    scanf(" %c",&operant);

    calc:
        switch (operant)
        {
        case '+':
            result = add(value1,value2);
            break;
        case '-':
            result = sub(value1,value2);
            break;
        case '*':
            result = mul(value1,value2);
            break;
        case '/':
            result = div(value1,value2);
            break;
        case '^':
            result = sqr(value1);
            break;
        case '?':
            result = sqroot(value1);
            break;
        case '~':
            result = inv(value1);
            break;
        default:
            break;
        }
        
        printf("Result = %f\n",result);

        printf("Do you wish to continue(Y/N):- \n");
        scanf(" %c",&opt);

        
}