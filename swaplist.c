#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	int val;
	struct node *next;
}node;
int main(void)
{
	node *ptr,*s,*start;
	s=NULL;
	for(int i=1;i<=5;i++)
	{
		ptr=(node *)(malloc(sizeof(node)));
		ptr->next=NULL;
		ptr->val=i;
		if(s==NULL)
		{
			s=ptr;
			start=ptr;
		}
		else
		{
			ptr->next=s;
			s=ptr;
		}
	}
	ptr=s;
	int x;
	x=start->val;
	start->val=ptr->val;
	ptr->val=x;
	while(ptr!=NULL)
	{
		printf("[%p]{%d %p}",ptr,ptr->val,ptr->next);
		ptr=ptr->next;
		printf("\n");
	}
	return 0;
}