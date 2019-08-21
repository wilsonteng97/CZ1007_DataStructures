#include <stdio.h>
int platform1D(int ar[], int size);
int main()

{
    int i,b[50],size;
    printf("Enter array size: \n");
    scanf("%d", &size);
    printf("Enter %d data: \n", size);
    for (i=0; i<size; i++)
        scanf("%d",&b[i]);
    printf("platform1D(): %d\n", platform1D(b,size));
    return 0;
}
int platform1D(int ar[], int size)
{
    /* Write your program code here */
    int i = 1, j = 0, length = 1, currentNum, prevNum, max;
    int lengthArr[20];

    while (i < size)
    {
        currentNum = ar[i];
        prevNum = ar[i-1];

        if (currentNum == prevNum)
            length++;

        if (currentNum != prevNum || i == size-1)
        {
            lengthArr[j] = length;
            length = 1;
            j++;
        }

        i++;
    }

    if (j == 0)
        return 1;
    else
        max = lengthArr[0];

    while (j > 0)
    {
        if (max < lengthArr[j-1])
        {
            max = lengthArr[j-1];
        }

        j--;
    }

    return max;
}
