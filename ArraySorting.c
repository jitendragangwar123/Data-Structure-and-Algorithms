#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void swap(int *a, int *b);
void quicksort(int *arr,int strt,int end);
void stend(int *arr,int n,int end);
void getArr(int *arr,int len);

void swap(int *a, int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
	return;
}

void quicksort(int *arr,int strt,int end)
{
	int i=0,j=0;
	
	for(i=0;i<=end;i++)
	{
		for(j=i+1;j<=end;j++)
		{
			if(arr[j]<arr[i])
				swap(&arr[i],&arr[j]);
		}
	}
	
	return;
}

void stend(int *arr,int n,int end)
{
	int sflag,eflag,i=0,c=0;
	while(i<=end)
	{
		if(arr[i]==n&&c==0)
		{
			sflag=i;
			c++;
		}
		if(arr[i]==n&&c!=0)
			eflag=i;
		
		i++;
	}
	if(c==0) printf("\nNo such number");	
	if(c!=0) printf("Starting Occurrence :%d\nEnding Occurrence :%d", sflag+1,eflag+1);
	return;
}

void getArr(int *arr,int len)
{
	int i=0;
	printf("Enter elements: \n");
	for(i=0;i<len;i++)
		scanf("%d",arr[i]);
		
	return;
}
		

void main()
{
	int *a,x,i,n=0;
   printf("Enter the Number of elements: ");
   scanf("%d",&n);
   a = (int*)calloc(n, sizeof(int*));
   printf("\n Unsorted Array : ");
   for(i=0;i<n;i++)
	   scanf("%d",&a[i]);

	quicksort(a,0,n-1);
	printf("\n Sorted Array :");
	
	for(i=0;i<n;i++)
	   printf("%d ",a[i]);
	
	printf("\n Value : ");
	scanf("%d",&x);
	
	stend(a,n,n-1);
	return;
}
		
	
		
	
