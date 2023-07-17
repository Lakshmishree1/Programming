-
#include<stdio.h>
#include<stdlib.h>

void read(int arr[10],int num);
void sort(int arr[10],int num);
void largest (int arr[10],int num);
void smallest (int arr[10],int num);


int main()
{

    int num,arr[100],i;
    printf("Enter the number of students\n");
    scanf("%d",&num);
    read (arr,num);
    sort (arr,num);
    largest(arr,num);
    smallest(arr,num);
    getch();
    return 0;

}
void read(int arr[10],int num)
{
    int i,marks,a[i];
    printf("Enter the ranks of the students\n");
    for(i=0;i<=10;i++)
    {
        scanf("%d\n",&a[i]);
    }
}
void sort(int arr[10],int num)
{
    int i,j,temp;
    printf("In ascending order\n");
    for(i=0;i<=(num-1);i++)
    {
        for(j=0;j<(num-i-1);j++)
        {
            if(arr[j]>arr[j+1])
            {
            temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
            }
        }
    }
    printf("arranging in ascending order\n");
for(i=0;i<num;i++)
    printf("%d",arr[i]);
}

void largest(int arr[10],int num)
{
    int i=0,large;
    large=arr[i];
    while(i<num)
    {
    if(large<arr[i])
    {
        large=arr[i];
        i++;
    }
     printf("The largest rank is %d\n",large);
    }

}
void smallest (int arr[10],int num)
{
    int i=0,small;
    small=arr[i];
    while(i<num)
    {
    if(small>arr[i])
    {
        small=arr[i];
        i++;
    }
    printf("The smallest rank is %d",small);
    }

}

