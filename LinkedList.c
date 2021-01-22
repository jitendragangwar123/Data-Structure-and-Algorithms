#include<stdlib.h>
#include <stdio.h>
#include <malloc.h>

void insert_at_first();     //insert at first position
void insert_at_middle();    //insert at middle position
void insert_at_end();       //insert at last position
void delete_at_first();     //delete at first position
void delete_at_middle();    //delete at middle position
void delete_at_end();       //delete at last position
void display();             //display linlkist
void search();              //search any value
void createnode();          //creating linklist


struct node
{
    int data;
    struct node *next;
};

typedef struct node node;
node *head=NULL;

void createnode()       //creating linklist
{
    node *temp;
    temp=(node*) malloc(sizeof(node));
    if (temp==NULL)
    {
        printf("memory is full");
        exit;
    }
    
    printf("\nenter the data\t");
    scanf("%d",&temp->data);
    temp->next=NULL;
    if(head==NULL)
        head=temp;
    else
    {
        node *q=head;
        while(q->next!=NULL)
        {
            q=q->next;
        }
        q->next=temp;
        temp=NULL;
        q=NULL;
    }
}



void insert_at_first()          //insert at first position
{
   node *q;
   q=(node *)malloc(sizeof(node));
   printf("enter value\n");
   scanf("%d",&q->data);
   q->next=head;
   head=q;
   q=NULL;
   display();
}

void insert_at_middle()     //insert at middle position
{
    int pos,x=1;
    node *q,*temp;
    q=head;
    
    printf("enter the position after which you want to insert a node\t");
    scanf("%d",&pos);
    temp=(node*)malloc(sizeof(node));
    printf("enter data\t");
    scanf("%d",&temp->data);
    temp->next=NULL;
    
    while(x!=pos)
    {
        q=q->next;
        x++;
    }
    temp->next=q->next;
    q->next=temp;
    
    display();
    
}

void insert_at_end()            //insert at last position
{
    node *q;
    q=(node*)malloc(sizeof(node));
    printf("enter data\n");
    scanf("%d",&q->data);
    q->next=NULL;
    if(head==NULL)
    {
        head=q;
    }
    else
    {
        node *temp;
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
            
        }
        temp->next=q;
        q=NULL;
        temp=NULL;
    }

    display();
}

void display()          //display linklist
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

void delete_at_first()          //delete at first position
{
    node *q;
    if(head==NULL)
    {
        printf("under flow\n");
    }
    else if(head->next==NULL)
    {
        q=head;
        head=NULL;
        q=NULL;
        free(q);
    }
    else
    {
        q=head;
        head=head->next;
        q=NULL;
        free(q);
    }
    display();
}


void delete_at_end()            //delete at end position
{
    node *q,*p;
    if(head==NULL)
    {
        printf("underflow\n");
    }
    else if(head->next==NULL)
    {
        delete_at_first();
    }
    else
    {
         q=head;
        while(q->next!=NULL)
        {
            p=q;
            q=q->next;
        }
        p->next=NULL;
        p=NULL;
        q=NULL;
        free(q);
    }
    display();
}


void delete_at_middle()         //delete at middle position
{
    node *q,*p=head;;
    int pos,x=1;
    printf("enter the position after which you want to delete");
    scanf("%d",&pos);
    if(x!=pos)
    {
        q=p;
        x++;
        p=p->next;
    }
    q->next=p->next;
    p=NULL;
    q=NULL;
    free(p);
    display();
}

void search()                 //search any value
{
    int num,flag=0;
    node *q=head;
    printf("enter value to search in linkedList\n");
    scanf("%d",&num);
    while(q)
    {
        if(num==q->data)
        {
            flag++;
            break;
        }
        else
        {
            q=q->next;
        }
    }
    if(flag==0)
        printf("value not found");
    else
        printf("value found");
}
int main()
{
   int n,x,i;
   int choice;
   char y;
   
   printf("enter the number of node in linkedList\t");
   scanf("%d",&n);
   for(i=0;i<n;i++)
   {
       createnode();
   }
   
   display();
   
    while(choice!=5)
   {
   printf("\nenter your choice \n");
   printf("1 Insert \t2 Delete \t3 Display \t4 Search \t5 Exit\n");
   scanf("%d",&n);

    
    switch(n)
    {
        
        case 1:
        printf("press\t1 enter fron front\t 2 enter from mid\t 3 enter from end");
        scanf("\n%d",&x);
        
        switch(x)
        
        {
            case 1:
            insert_at_first();          //calling for insert at first position
            break;
            case 2:
            insert_at_middle();         //calling for insert at middle position
            break;
            case 3:
            insert_at_end();            //calling for insert at end position
            break;
            default:
            printf("wrong choice\n");
        }
        
        break;

        case 2:
        printf("press\t1 delete  from front\t 2 delete from mid\t 3 delete from end");
        scanf("\n%d",&x);
        
        switch(x)
        
        {
            case 1:
            delete_at_first();          //calling for delete at first position
            break;
            case 2:
            delete_at_middle();         //calling for delete at middle position
            break;
            case 3:
            delete_at_end();            //calling for delete at last position
            break;
            default:
            printf("\nwrong choice");
        }
        
        break;

        case 3:
            display();              //calling for display the linklist
            break;
        
        case 4:
            search();               //calling for searching the element in the linkedList
            break;
        case 5:
            exit(1);                //for exit from the option
            
        default:
            printf("wrong choice\n");       //wrong choice
        
   }
} 

    return 0;
}

