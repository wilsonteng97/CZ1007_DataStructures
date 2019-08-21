#include <stdio.h>

int main() {
    float farenheit, celsius; // declare variables

    printf("Enter the temperature in degree F: \n");
    scanf("%f", &farenheit);

    celsius = (5.0/9)*(farenheit-32);

    printf("Converted degree in C: %.2f\n", celsius);
    return 0;
}
