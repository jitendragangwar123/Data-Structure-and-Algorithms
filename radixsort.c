#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node *prev;
	int data;
	struct node *next;
};
struct node* get_node(int item)
{
	struct node *t=(struct node*) malloc(sizeof(struct node));
	t->data=item;
	t->next=NULL;
	t->prev=NULL;
	return t;
}
int find_max(int a[],int n)
{
	int max=a[0];
	for(int i=1;i<n;i++)
		if(max<a[i]) max=a[i];
		
		return max;
}
int find_digits(int n)
{
	int count=0;
	while(n!=0)
	{
		n=n/10;
		count++;
	}
	return count;
}
struct node* doubly_linked_list(int a[],int n)
{
	struct node *head=get_node(a[0]);
	struct node *t;
	for(int i=1;i<n;i++)
	{
		struct node *new_node=get_node(a[i]);
		t=head;
		while(t->next!=NULL) t=t->next;
		t->next=new_node;
		new_node->prev=t;
	}
	return head;
}
void display(struct node *t)
{
	while(t!=NULL)
	{
		printf("%d ",t->data);
		t=t->next;
	}
}
void Radix_sort(struct node *head,int digits)
{
	for(int i=1,j=1;j<=digits;i=i*10,j++)
	{
	struct node *comp;
	struct node *curr;
	curr=head->next;
	while(curr!=NULL)
	{
		int key=curr->data;
		int current=curr->data/i;
		current=current%10;
		comp=curr->prev;
		int compare=comp->data/i;
		compare=compare%10;
		while(comp!=NULL && compare>current)
		{
			(comp->next)->data=comp->data;
			comp=comp->prev;
			if(comp!=NULL)
			{
			compare=comp->data/i;
			compare=compare%10;
			}
		}
		if(comp!=NULL) (comp->next)->data=key;
		else head->data=key;
		curr=curr->next;
	}
    }
}
int main()
{
	int n,i;
//	printf("enter no.of elements ");
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	if(n<=0) 
	{
		printf("INVALID INPUT");
		return 0;
	}
	for(i=0;i<n;i++) 
	{
	    if(a[i]<0)
	    {
	        printf("INVALID INPUT");
		    return 0;	
	    }
    }
	int max=find_max(a,n);
	int digits=find_digits(max);
	struct node *head=doubly_linked_list(a,n);
	Radix_sort(head,digits);
	display(head);
	return 0;
}