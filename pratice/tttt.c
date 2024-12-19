#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*head=NULL;

void insert(int value)
{
    struct Node *t,*tail=NULL;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=value;
    t->next=NULL;
    if(head==NULL)
    {
        head=tail=t;
    }
    else
    {
        tail->next=t;
        tail=t;
    }
}

void display(struct Node *p)
{
    while(p!=NULL)
    {
        printf("%d=>",p->data);
        p=p->next;
    }
}

int main()
{
    int arr[]={34,56,7,8,90};
    int i;
    for(i=0;i<5;i++)
    {
        insert(arr[i]);
    }
    display(head);
    return 0;

}
