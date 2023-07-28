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
	ptr=(node*)(malloc(sizeof(node)));
	ptr1=(node*)(malloc(sizeof(node)));
	int n;
	printf("Enter the number of nodes in the list");
	scanf("%d",&n);
	int i,num;
	s=NULL;
	for(i=0;i<n;i++)
	{
		ptr=(node*)(malloc(sizeof(node)));
		printf("Enter value");
		scanf("%d",&num);
		ptr->val=num;
		ptr->next=NULL;
		if(s==NULL)
		{
		  s=ptr;	
		}
		else
		{
			ptr->next=s;
			s=ptr;
		}
		
	}
	ptr=s;
	
	while(ptr!=NULL)
	{
		printf("[%p]{%d %p}",ptr,ptr->val,ptr->next);
		ptr=ptr->next;
		printf("\n");
	}
	printf("Deletion");
	ptr=s;
	while(ptr->next->next!=NULL)
	{
		ptr=ptr->next;
	}
	ptr1=ptr->next;
	ptr->next=NULL;
	free(ptr1);
	printf("After deletion");
	ptr=s;
	
	while(ptr!=NULL)
	{
		printf("[%p]{%d %p}",ptr,ptr->val,ptr->next);
		ptr=ptr->next;
		printf("\n");
	}
	
	
	
	
	
}