#include<stdio.h>
void enQueue(int data);
void deQueue();
void display();
typedef struct node
{
    int age,size;
    struct node*next;
}node;
struct node*front;
struct node*rear;
main()
 {
     int n,m,age,data;
     enQueue(data);
     deQueue();
     display();


      void createnode()
 {
     int age,size;
     struct node*newnode;
     newnode=(struct node*)malloc(sizeof(struct node));
     newnode->n=data;
     newnode->link=next;

}
 void enQueue(int size )
{
    struct node*newnode;
    if(front=size-1)
    {
        printf("The Queue is full\n");
    }
    rear->next=newnode;
    rear=newnode;
}
void display()
{
    struct node *temp;
    if(front=rear=-1)
    {
        printf("No items in the list\n");
    }
    else
    {
        temp=front;
        while(temp!=NULL)
        pridatatf("%d",temp->data);
        pridatatf("%d",temp->data);
    }
}
 }

