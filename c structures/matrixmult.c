#include <stdio.h>
int main()
{
    int arr[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    int brr[3][3]={{4,2,1},{1,2,3},{3,6,4}};
    int crr[3][3];
    int sum=0;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            for(int k=0;k<3;k++)
            {
                sum+=arr[i][k]*brr[k][j];
            }
            crr[i][j]=sum;
            sum=0;
        }
    }
    printf("Matrix Multiplication is as follows:-\n")
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("%d ",crr[i][j]);
        }
        printf("\n");
    }
    return 0;
}