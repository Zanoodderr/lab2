#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f( double x )  // основна функція
{
    double y;

    y = pow(x,2) + 2*x;
    //y = x;

    return y;
}
double left_rectangle(double a, double b, double measurement_error, unsigned int n);
double right_rectangle(double a, double b, double measurement_error, unsigned int n);
double trap (double a, double b, double measurement_error, unsigned int n);
double Simpson (double a, double b, double measurement_error, unsigned int n);

int main()
{
    double a, b, measurement_error, I1, I2;
    int n, var, i;

    printf("\n\t*===================================*");
    printf("\n\t|=__*-----------lab2------------*__=|");
    printf("\n\t|=__*----------Integral---------*__=|");
    printf("\n\t*===================================*\n");

    printf("\n\tEnter the left boundary of integration\n  X(first)=");
    scanf("%lf", &a);

    printf("\n\tEnter the right boundary of integration\n  X(last)=");
    scanf("%lf", &b);

    do{
    printf("\tEnter the number of partition intervals (N>0)\nN=");
    scanf("%u", &n);
    }while(n <= 0);

    printf("\n\tEnter the measurment error of integration\n  Measurment error=");
    scanf("%lf", &measurement_error);

    do
    {
        printf("\nChoose the method of calculating:\n");
        printf("\t1. By Left Rectangles method:\n");
        printf("\t2. By Right Rectangles method:\n");
        printf("\t3. By Trapezoid method:\n");
        printf("\t4. By Simpson's method (parabola method):\n");
        scanf("%u", &var);

            if (var!=1 && var!=2 &&var!=3 &&var!=4)
                printf("\nYou are mistaken\n");
    }while (var!=1 && var!=2 && var!=3 && var!=4);

    system("cls");

    switch(var)
         {

         case 1:
            {
                printf("\n\n\t======*Left Rectangles method*======\n");
                I1 = left_rectangle(a, b, measurement_error, n);

                for (i = 0; i < 2; i++) {
                    if (i == 1){
                        n += 2;
                        I2 = left_rectangle(a, b, measurement_error, n);
                    }
                        if (fabs(I1 - I2) <= measurement_error) {
                            break;
                        }
                    else {
                        i = 0;
                    }
                }

            } break;

         case 2:
            {
                printf("\n\n\t======*Right Rectangles method*======\n");
                I1 = right_rectangle(a, b, measurement_error, n);
                for (i = 0; i < 2; i++) {
                    if (i == 1){
                        n += 2;
                        I2 = right_rectangle(a, b, measurement_error, n);
                        if (fabs(I1 - I2) <= measurement_error) {
                            break;
                        }
                    }
                    else {
                        i = 0;
                    }
                }

            } break;

         case 3:
            {
                printf("\n\n\t======*Trapezoid method*======\n");
                I1 = trap(a, b, measurement_error, n);
                for (i = 0; i < 2; i++) {
                    if (i == 1){
                        n += 2;
                        I2 = trap(a, b, measurement_error, n);
                        if (fabs(I1 - I2) <= measurement_error) {
                            break;
                        }
                    }
                    else {
                        i = 0;
                    }
                }

            } break;

         case 4:
            {
                printf("\n\n\t======*Simpson's method (parabola method)*======\n");
                I1 = Simpson(a, b, measurement_error, n);
                for (i = 0; i < 2; i++) {
                    if (i == 1){
                        n += 2;
                        I2 = Simpson(a, b, measurement_error, n);
                        if (fabs(I1 - I2) <= measurement_error) {
                            break;
                        }
                    }
                    else {
                        i = 0;
                    }
                }
            }
         }

    printf("\n\ta = %.2lf    \n\tb = %.2lf   \n\tIntegral = %.8lf   \n\tN = %d", a, b, I2, n);

    return 0;
}

double left_rectangle(double a, double b, double measurement_error, unsigned int n)
{
    double sum=0, x, h;
    unsigned int i;

    h = ( b - a ) / n;
    x = a;

    for (i = 0;  i < n;  i++ ){
      sum += f(x);
      x += h;
    }

    return sum*h;
}

double right_rectangle(double a, double b, double measurement_error, unsigned int n)
{
    double sum, x, h;
    unsigned int i;

    h = ( b - a ) / n;
    x = a + h;

    for (i = 0;  i < n;  i++ ){
      sum += f(x);
      x += h;
    }

    return sum*h;
}

double trap (double a, double b, double measurement_error, unsigned int n)
{
    double sum, x, h;
    unsigned int i;

    h = ( b - a ) / n;
    x = a;

    for (i = 0;  i < n;  i++ ){
      sum += ( f(x) + f( x + h ) ) / 2;
      x += h;
    }

    return sum*h;
}

double Simpson (double a, double b, double measurement_error, unsigned int n)
{
    double sum, sum1, sum2, x, h;
    unsigned int i;

    sum = f(a) + f(b);
    h = ( b - a ) / n;
    x = a;

    for (i = 0;  i < n;  i++ ){
      sum1 += f(x);
      x += 2*h;
    }

    x = a + h;

    for (i = 1;  i < n-1;  i++ ){
      sum2 += f(x);
      x += 2*h;
    }

    sum += 4*sum1 + 2*sum2;

    return (h/3) * sum;
}
