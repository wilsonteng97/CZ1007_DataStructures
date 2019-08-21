#include <stdio.h>

int main() {
    int ccount = 0, dcount = 0;
    char ch;
    printf("Enter your characters (# to end): \n");
    scanf("\n%c", &ch);

    while (ch != '#') {
        if (ch >= '0' && ch <= '9') {
            dcount++;
        }
        else if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
            ccount++;
        }
        scanf("%c", &ch);
    }

    printf("The number of digits: %d \n", dcount);
    printf("The number of letters: %d \n", ccount);
    return 0;
}
