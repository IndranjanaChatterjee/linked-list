#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int value;
	struct node *next;
}node;
int main()
{
	node *ptr,*ptr1,*s,*p;
	s=NULL;
	ptr=(node*)(malloc(sizeof(node)));
	int i;
	for(i=1;i<=5;i++)
	{
		ptr=(node*)(malloc(sizeof(node)));
		ptr->next=NULL;
		ptr->value=i;
		
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
		printf("\n%d",ptr->value);
		ptr=ptr->next;
	}
	printf("\n");
	ptr1=s;
	while(ptr1!=NULL)
	{
		p=ptr1->next;
		while(p!=NULL)
		{
			if(ptr1->value>p->value)
			{
			   i=ptr1->value;
			   ptr1->value=p->value;
			   p->value=i;	
			}
			p=p->next;
		}
		ptr1=ptr1->next;
		
	}
	ptr1=s;
	while(ptr1!=NULL)
	{
		printf("\n%d",ptr1->value);
		ptr1=ptr1->next;
	}
	printf("\n");
}