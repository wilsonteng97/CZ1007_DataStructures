#include <stdio.h>

int main() {
    float d, t, speed;

    printf("Enter distance (in km): \n");
    scanf("%f", &d);
    printf("Enter time (in sec): \n");
    scanf("%f", &t);

    speed = d / t;
    printf("The speed is %.2f km/sec \n", speed);
    return 0;
}
