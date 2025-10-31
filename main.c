#include <stdio.h>
#include "Calc.c"
#include <stdlib.h>

//For Initial Purpose,We are taking type of operation and values separately (May Change Later)

extern int ctr = 0;
extern int i = 1;


void mem(int ctr,char *free,double x,double y,double z,char *o){
    char operators{} = calloc(sizeof(char),3);
    double mem{} = calloc(sizeof(double),1);


    if ((opt-32) != 'Y' || opt != 'Y'){
        // for(int j = 0; j <(sizeof(mem)/sizeof(mem[0])); ++j){
        //     for(int k = j+1; k < (j+2);++k){
        //         printf("%lf",operators[j]);
        //         printf("%c%lf=%lf;\t",mem[j],operators[])
        //     }
        // }
        continue;
    }
    else if ((sizeof(mem)/sizeof(mem[0])) < ctr){
        realloc(operators,ctr*2);
    }
    else{
        mem[i] = o;
        if (i =< 3){
            do{
                operators[i] = (i%3==0) ? z : (i%2==0) ? y : x;
                ++i;
            }
        }
    }
}



void main()
{
    double value1,value2;
    char operant;
    double result;
    char opt;


    printf("Enter Value 1 and 2(Second Value can be zero for square,square root and reciprocal):- \n");
    scanf("%lf %lf",&value1,&value2);
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
        printf("Result = %lf\n",result);
        ++ctr;

        printf("Do you wish to continue(Y/N):- \n");
        scanf(" %c",&opt);
        mem();

        while ((opt-32) == 'Y' || opt == 'Y')
        {
            value2=0;
            printf("Enter Value:- \n");
            scanf("%lf",&value2);
            printf("Enter Operant(+,-,*,/,^(square),?(square root),~(reciprocal)):- \n");
            scanf(" %c",&operant);

            value1 = result;
            goto calc;
        }
}