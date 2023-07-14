#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	int val;
	struct node *next;
}node;
int main(void)
{
	node *ptr,*s;
	s=NULL;
	for(int i=1;i<=5;i++)
	{
		ptr=(node *)(malloc(sizeof(node)));
		ptr->next=NULL;
		ptr->val=i;
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
	return 0;
}