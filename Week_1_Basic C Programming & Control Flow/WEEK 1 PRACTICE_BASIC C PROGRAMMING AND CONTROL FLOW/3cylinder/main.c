#include <stdio.h>
#define PI 3.1416

int main() {
    float r, h, volume, area;
    printf("Enter the radius: \n");
    scanf("%f", &r);
    printf("Enter the height: \n");
    scanf("%f", &h);

    volume = PI * r * r * h;
    area = (2 * PI * r) * (h + r);

    printf("The volume is: %.2f \n", volume);
    printf("The surface area is: %.2f \n", area);
    return 0;
}
