#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Calc.h"

int ctr = 0;

typedef struct {
    double a;
    double b;
    double result;
    char op;
} OpEntry;

void memory(char fr, double x, double y, double z, char o) {
    static OpEntry *history = NULL;
    static size_t capacity = 0;

    /* main() increments ctr before calling memory(), so current entry index is ctr-1 */
    size_t index = (ctr > 0) ? (size_t)(ctr - 1) : 0;

    if (fr == 'Y' || fr == 'y') {
        /* ensure capacity for index */
        if (index + 1 > capacity) {
            size_t newcap = (capacity == 0) ? 4 : capacity * 2;
            while (newcap < index + 1) newcap *= 2;
            OpEntry *tmp = realloc(history, newcap * sizeof(*history));
            if (!tmp) {
                /* allocation failed: keep old history and bail */
                return;
            }
            history = tmp; 
            capacity = newcap;
        }

        /* store entry at 0-based index */
        history[index].a = x;
        history[index].b = y;
        history[index].result = z;
        history[index].op = o;
    } else {
        /* print current operation */
        printf("%lf %c %lf = %lf;\n", x, o, y, z);

        /* print stored history (if any) */
        if (ctr > 0 && history != NULL) {
            for (size_t i = 0; i < (size_t)(ctr-1); ++i) {
                printf("%lf %c %lf = %lf;\n",
                    history[i].a,
                    history[i].op,
                    history[i].b,
                    history[i].result);
            }
        }

        /* free history */
        free(history);
        history = NULL;
        capacity = 0;
    }
}
// ...existing code...
int main()
{
    double value1,value2;
    char operant;
    double result;
    char opt;


    printf("Enter Value 1 and 2 (Second Value can be zero for square, square root and reciprocal):\n");
    if (scanf("%lf %lf", &value1, &value2) != 2) return 1;
    printf("Enter Operant (+,-,*,/,^(square),?(square root),~(reciprocal)):\n");
    if (scanf(" %c", &operant) != 1) return 1;

    for (;;) {
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
            result = division(value1,value2);
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
            printf("Unknown operator '%c'\n", operant);
            return 1;
        }

        printf("Result = %lf\n", result);
        ++ctr;

        printf("Do you wish to continue (Y/N):\n");
        if (scanf(" %c", &opt) != 1) return 1;
        memory(opt, value1, value2, result, operant);

        if (opt == 'Y' || opt == 'y') {
            value1 = result;
            value2 = 0;
            printf("Enter Value:\n");
            if (scanf("%lf", &value2) != 1) return 1;
            printf("Enter Operant (+,-,*,/,^(square),?(square root),~(reciprocal)):\n");
            if (scanf(" %c", &operant) != 1) return 1;
            continue;
        }

        break;
    }

    return 0;
}