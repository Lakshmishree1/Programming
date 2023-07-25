#include <stdio.h>
#include <stdlib.h>
struct Doc
{
    char name[20];
    int age;
    float sal;
    struct Doc *next;
};
typedef struct Doc* node;
node CreateNode()
{
    node t;
    t=(node *)malloc(sizeof(struct Doc));
    if(t==NULL)
    {
        printf("\nNot Created\n");
        exit(0);
    }
    printf("\nEnter name,age,salary");
    scanf("%s%d%f",t->name,&t->age,&t->sal);
    t->next=NULL;
    return t;
}
void display_list(node first)
{
    node t;
    if(first==NULL)
    {
        printf("\nEmpty List");
        return;
    }
    printf("\nDoctors are:\n");
    t=first;
    while(t->next!=NULL)
    {
        printf("\n%s\t%d\t%f",t->name,t->age,t->sal);
        t=t->next;
    }
    printf("\n");
}
node insert_front(node first)
{
    node t,c;
    t=CreateNode();
    if(first==NULL)
        return t;
    t->next=first;
    return t;
}
node delete_front(node head)
{
    node cur;
    cur=head;
    head=head->next;
    printf("Doctor Deleted:\n");
    printf("%s",cur->name);
    free(cur);
    return head;
}
void search(node first, char s[10])
{
  node t;
  int f=0;
    t=first;
    while(t!=NULL)
    {
        if(strcmp(t->name,s)==0)
        {
            f=1;
            break;
        }
        t=t->next;
    }
    if(f==1)
        printf("\nExisting");
    else
        printf("\nNot Existing");
}
void max(node first)
{
    node t;
    float maxi=0;
    t=first;
    while(t!=NULL)
    {
        if(t->sal>maxi)
        {
            maxi=t->sal;
        }
        t=t->next;
    }
        t=first;
    while(t!=NULL)
    {
        if(t->sal==maxi)
        {
          printf("%s\t%d\t%f",t->name,t->age,t->sal);
        }
        t=t->next;
    }

}
int main()
{
    node first=NULL;
    int ch;
    char s[10];
    for(;;)
    {
        printf("\n1-Insert\n2Delete\n3-Search\n4-Display\n5->EXIT");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:first=insert_front(first);
            break;

            case 2:first=delete_front(first);
            break;
            case 3:printf("\nEnter name to search:");
                   scanf("%s",s);
                   search(first,s);
            case 4:display_list(first);
            break;
            case 5:exit(0);
        }
    }
    return 0;
}

