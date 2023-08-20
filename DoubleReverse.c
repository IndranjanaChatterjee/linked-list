#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int value;
	struct node *next;
	struct node *prev;
}node;
int main()
{
	node *ptr,*start,*ptr1,*q,*t;
	ptr=(node *)(malloc(sizeof(node)));
	ptr1=(node *)(malloc(sizeof(node)));
	start=NULL;
	int n;
	printf("Enter the number of nodes:");
	scanf("%d",&n);
	int i;
	int val;
	printf("\nEnter values\n");
	for(i=0;i<n;i++)
	{
		ptr=(node *)(malloc(sizeof(node)));
		ptr1=(node *)(malloc(sizeof(node)));
		scanf("%d",&val);
		ptr->value=val;
		ptr->next=NULL;
		ptr->prev=NULL;
		
		if(start==NULL)
		{
			
			start=ptr;
		}
		else
		{
			ptr1=start;
			while(ptr1->next!=NULL)
			{
				ptr1=ptr1->next;
			}
			ptr1->next=ptr;
			ptr->prev=ptr1;
			
		}
		
	}
	ptr1=start;
	printf("\nPrinting original list\n");
	while(ptr1!=NULL)
	{
		printf("\n[%p][%p %d %p]",ptr1,ptr1->prev,ptr1->value,ptr1->next);
	    ptr1=ptr1->next;
	}
	ptr1=start;
	q=NULL;
	while(ptr1!=NULL)
	{
		t=ptr1->next;
		ptr1->next=q;
		ptr1->prev=t;
		q=ptr1;
		ptr1=t;
		
	}
	ptr1=q;
	printf("\nPrinting reversed list\n");
	while(ptr1!=NULL)
	{
		printf("\n[%p][%p %d %p]",ptr1,ptr1->prev,ptr1->value,ptr1->next);
	    ptr1=ptr1->next;
	}
	
	return 0;
}
