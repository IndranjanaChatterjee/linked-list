#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	int val;
	struct node *next;
	struct node *prev;
}node;
int main()
{
	node *ptr,*ptr1,*s;
	ptr=(node*)(malloc(sizeof(node)));
	s=NULL;
	int x,i;
	for (i=0;i<5;i++)
	{
		ptr=(node*)(malloc(sizeof(node)));
		ptr->next=NULL;
		ptr->prev=NULL;
		ptr->val=i;
		if(s==NULL)
		{
			s=ptr;
		}
		else
		{
			ptr->next=s;
			s->prev=ptr;
			s=ptr;
		}
	}
	ptr=s;
	while(ptr!=NULL)
	{
		printf("[%p]{%d %p %p}",ptr,ptr->val,ptr->next,ptr->prev);
		ptr=ptr->next;
		printf("\n");
	}
	printf("Enter a val you want to delete");
	scanf("%d",&x);
	ptr=s;
	while(ptr!=NULL && ptr->val!=x)
	{
		ptr=ptr->next;
	}
	if(ptr->prev==NULL)
	{
		ptr->next->prev=NULL;
		s=ptr->next;
		free(ptr);
	}
	
	else if(ptr!=NULL)
	{
		ptr->prev->next=ptr->next;
		ptr->next->prev=ptr->prev;
		//ptr1->next->prev=ptr;
	    free(ptr);
	    
		
	}
	ptr=s;
	while(ptr!=NULL)
	{
		printf("[%p]{%d %p %p}",ptr,ptr->val,ptr->next,ptr->prev);
		ptr=ptr->next;
		printf("\n");
	}
	
}
