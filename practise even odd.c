#include<stdio.h>
void main()
{
    int arr1[5],arr2[5],sumarr[5],i;
    printf("enter the value of first array\n");
    for(i=0;i<5;i++)
    scanf("%d",&arr1[i]);
    printf("enter the value of sec array\n");
    for(i=0;i<5;i++)
    scanf("%d",&arr2[i]);
    for(i=0;i<5;i++)
    {
    sumarr[i]=arr1[i]+arr2[i];
    printf("\nvalue=%d",sumarr[i]);
    }

}
