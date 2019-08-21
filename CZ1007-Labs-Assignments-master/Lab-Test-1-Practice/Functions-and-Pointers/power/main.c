#include <stdio.h>
#include <math.h>
float power1(float num, int p);
void power2(float num, int p, float *result);
int main()
{
    int power;
    float number, result=-1;

    printf("Enter the number and power: \n");
    scanf("%f %d", &number, &power);
    printf("power1(): %.2f\n", power1(number, power));
    power2(number,power,&result);
    printf("power2(): %.2f\n", result);
    return 0;
}
float power1(float num, int p)
{
    /* Write your program code here */
    return pow(num, p);
}
void power2(float num, int p, float *result)
{
    /* Write your program code here */
    *result = pow(num, p);
}
