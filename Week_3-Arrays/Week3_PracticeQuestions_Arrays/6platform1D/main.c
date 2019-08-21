#include <stdio.h>
int platform1D(int ar[], int size);

int main()
{
    int i,b[50],size;
    printf("Enter array size: \n");
    scanf("%d", &size);
    printf("Enter %d data: \n", size);
    for (i=0; i<size; i++)
    {
        scanf("%d",&b[i]);
    }
    printf("platform1D(): %d\n", platform1D(b,size));
    return 0;
}

int platform1D(int ar[], int size)
{
    int i, count=1, index=0, max;
    int arb[size];
    for (i=0;i<size;i++)
    {
        if (ar[i]==ar[i+1])
        {
            count += 1;
        }
        else if (ar[i]!=ar[i+1] || i == size-1)
        {
            arb[index] = count;
            count = 1;
            index++;
            arb[index] = 0;
        }
    }
    i = 0;
    if (index==0)
    {
        max = 1;
    }
    else
    {
        max = arb[0];
        while (index>=0)
        {
            if (arb[index]>max)
            {
                max = arb[index];
            }
            index--;
        }
    }
    return max;
}
