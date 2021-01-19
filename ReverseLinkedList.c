#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void add();
void delete();
void disp();
void search();
void reverse(struct node **);


struct node
{
	int data;
	struct node *link;
};

struct node *current_node, *new_node, *head;

void add()
{
	new_node=(struct node *)malloc(sizeof (struct node *));
	new_node->link=NULL;
	printf("\nEnter a Number: ");
	scanf("%d",&new_node->data);
	if(head == NULL)
		head = new_node;
	
	else 
	{
		new_node->link = head;
		head = new_node;
	}
	return;
}

void delete()
{
	int n;
	struct node *prober, *del;
	printf("\nEnter a Number to be deleted from Linked List: ");
	scanf("%d",&n);
	prober = head;
	
	while(prober -> link)
	{
		if(prober->link->data==n)
		{
			del = prober->link;
			prober->link = prober->link->link;
			free(del);
		}
		prober=prober->link;
	}
	return;
}

void disp()
{
	struct node *prober;
	prober=head;
	while(prober)
	{
		printf("%d ",prober->data);
		prober=prober->link;
	}
	return;
}
void search()  
{  
    struct node *prober;  
    int item,i=0,flag;  
    prober = head;   
    if(prober == NULL)  
    {  
        printf("\nEmpty List\n");  
    }  
    else  
    {   
        printf("\nEnter item which you want to search?\n");   
        scanf("%d",&item);  
        while (prober!=NULL)  
        {  
            if(prober->data == item)  
            {  
                printf("item found at location %d ",i+1);  
                flag=0;  
            }   
            else  
            {  
                flag=1;  
            }  
            i++;  
            prober = prober -> link;  
        }  
        if(flag==1)  
        {  
            printf("Item not found\n");  
        }  
    }     
    
    void reverse(struct node **head)
{
    struct node *p, *q, *r;
 
    p = q = r = *head;
    p = p->link->link;
    q = q->link;
    r->link = NULL;
    q->link = r;
 
    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->link;
        q->link = r;
    }
    *head = q;
}
 }  
void main()
{
	int n;int x=1;
	while(x)
	{
		printf("Choose an action: \nEnter 1 to add a node\nEnter 2 to delete a node\nEnter 3 to display the linked list\nEnter 4 to search the element\nEnter 5 to Reverse of linked list");
		scanf("%d",&n);
	switch (n)
		{
			case 1: add(); break;
			case 2: delete(); break;
			case 3: disp(); break;
			case 4: search(); break;
			//case 5: reverse(); break;
			case 6: x=0; break;
			default: printf("\nChoose from mentioned options only!\n");
		}
}
	return;
}

