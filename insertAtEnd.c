#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	int val;
	struct node *next;
}node;
int main()
{
	node *ptr,*s,*ptr1;
	ptr=(node *)(malloc(sizeof(node)));
	ptr1=(node *)(malloc(sizeof(node)));
	s=NULL;
	int n;
	printf("Enter the number of nodes");
	scanf("%d",&n);
	int i,num;
	for(i=0;i<n;i++)
	{
		ptr=(node *)(malloc(sizeof(node)));
		ptr1=(node *)(malloc(sizeof(node)));
		printf("enter value");
		scanf("%d",&num);
		ptr->val=num;
		ptr->next=NULL;
		if(s==NULL)
		{
			s=ptr;
		}
		else
		{
			ptr1=s;
			while(ptr1->next!=NULL)
			{
				ptr1=ptr1->next;
			}
			ptr1->next=ptr;
			
		}
	}
	
	ptr1=s;
	while(ptr1!=NULL)
	{
		printf("[%p](%d %p)",ptr1,ptr1->val,ptr1->next);
		ptr1=ptr1->next;
		printf("\n");
	}
	
	
}