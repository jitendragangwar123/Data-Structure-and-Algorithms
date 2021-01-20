#include <stdio.h>
#include<malloc.h>
#include<stdlib.h>

void createnode();
void display();
void reverse();

struct node
{
    int data;               //structure declaration
    struct node *next;
};

typedef struct node node;   //node is the type of variable node

node *head=NULL;

//Start the main function
int main()
{
   int n,x,i;
   char y;
   
   printf("Enter the number of node in linkedlist:\n");
   scanf("%d",&n);
   for(i=0;i<n;i++)

   {
       createnode();            //creating  the linkedlist
   }

   printf("Display the LinkedList:\n");
   display();                   //display the linkedlist
   reverse();                   // reverse the linkedlist
   printf("\nDisplay the Reverse LinkedList:\n");
   display();
}

void createnode()
{
    node *temp;         //creating node type pointer variable
    temp=(node*) malloc(sizeof(node));      //memory allocation 
    if (temp==NULL)                         //whose size equal to node data type
    {
        printf("memory is full");
        exit(0);
    }
    
    printf("Enter the Node in LinkedList:\n");
    scanf("%d",&temp->data);
    temp->next=NULL;
    
    if(head==NULL)              //if node is first node
        head=temp;
    else
    {
        node *q=head;
        while(q->next!=NULL)    //if node is not a first node    
        {
            q=q->next;
        }
        q->next=temp;
        temp=NULL;
        q=NULL;
    }
}

void display()
{
    node *q;
    q=head;
    while(q)
    {
        printf("%d->",q->data);
        q=q->next;              
    }
    q=NULL;
}

void reverse()
{
    node *p=NULL, *q=NULL, *r=head;
    while(r)
    {
        q=r->next;
        r->next=p;      //reversing the linkedlist
        p=r;
        r=q;
    }
    head=p;
}


