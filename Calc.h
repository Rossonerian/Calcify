#include <stdio.h>
#include <math.h>
//assuming only 2 inputs are entered initially
extern float add(float a,float b)
{
    return (a+b);
}
extern float sub(float a,float b)
{
    float d=a-b;
    return d;
}
extern float mul(float a,float b)
{
    return (a*b);
}
extern float division(float a,float b)
{
    return (a/b);
}
extern float sqr(float a)
{
    return (a*a);
}
extern double sqroot(float a)
{   double d=sqrt(a);
    return d;
}
extern double inv(float a)
{
    return (1/a);
}
