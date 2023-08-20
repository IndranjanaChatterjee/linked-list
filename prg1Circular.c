#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int value;
	struct node *next;
}node;
int main()
{
	node *ptr,*start,*ptr1;
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
		if(start==NULL)
		{
			ptr->next=ptr;
			start=ptr;
		}
		else
		{
			ptr1=start;
			while(ptr1->next!=start)
			{
				ptr1=ptr1->next;
			}
			ptr1->next=ptr;
			ptr->next=start;
		}
		
	}
	ptr1=start;
	while(ptr1->next!=start)
	{
		printf("\n[%p][%d %p]",ptr1,ptr1->value,ptr1->next);
	    ptr1=ptr1->next;
	}
	printf("\n[%p][%d %p]",ptr1,ptr1->value,ptr1->next);
	return 0;
}