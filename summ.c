#include<stdio.h>
int multi(int a,int b);
int main()
{
int sum,a,b,multiply;
printf("enter the numbers which u want to add\n");
scanf("%d%d",&a,&b);
sum=a+b;
printf("The sum is %d\n",sum);
multiply=multi(a,b);

}
int multi(int a,int b)
{
    int multiply;
    multiply=a*b;
    printf("the multipliaction is:%d\n",multiply);

}

