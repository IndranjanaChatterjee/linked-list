#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	int val;
	struct node *next;
}node;
int main()
{
	node *ptr,*ptr1,*s;
	ptr=(node*)(malloc(sizeof(node)));
	ptr1=(node*)(malloc(sizeof(node)));
	s=NULL;
	int n;
	printf("enter the number of nodes in the list ");
	scanf("%d",&n);
	int i,x;
	for(i=0;i<n;i++)
	{
		ptr=(node*)(malloc(sizeof(node)));
	    ptr1=(node*)(malloc(sizeof(node)));
	    printf("enter value");
	    scanf("%d",&x);
	    ptr->next=NULL;
	    ptr->val=x;
	    if(s==NULL)
	    {
	    	s=ptr;
		}
		else
		{
			ptr1=s;
			if(ptr1->val<x)
			{
				ptr->next=ptr1;
				s=ptr;
			}
			else
			{
				while(ptr1->next!=NULL && ptr1->next->val>x)
				{
					ptr1=ptr1->next;
				}
				if(ptr1->next==NULL)
				{
					ptr1->next=ptr;
				}
				else
				{
					ptr->next=ptr1->next;
					ptr1->next=ptr;
				}
				
			}
		}
	}
  printf("In Descending order\n");
  ptr=s;
  
  while(ptr!=NULL)
    {
      printf("[%p] {%d %p} \n",ptr,ptr->val,ptr->next);
      ptr=ptr->next;
    }
  
  return 0;
}