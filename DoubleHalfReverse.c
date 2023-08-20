#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int value;
	struct node *next;
	struct node *prev;
}node;
void reverse(node **q,node **s)//function to reverse
{
	node *t;
	*q=NULL;
	
	while((*s)!=NULL)
	{
		t=(*s)->next;
		(*s)->next=(*q);
		(*s)->prev=t;
		(*q)=(*s);
		(*s)=t;
		
	}
	
}
int main()
{
	node *ptr,*start,*ptr1,*one,*one1,*two,*two1;
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
	printf("\nRearranged\n");
	n=n/2;
	while(n!=0)
	{
		
		ptr1=ptr1->next;
		
		n--;
	}//dividing

	one=(node *)(malloc(sizeof(node)));
	two=(node *)(malloc(sizeof(node)));
	two=ptr1;

	ptr1->prev->next=NULL;
	ptr1->prev=NULL;

	
	one=start;
	
	reverse(&one1,&one);
	reverse(&two1,&two);
	start=NULL;
	
	while(one1->next!=NULL)
	{
		if(start==NULL)
		{
			start=one1;
		}
		
		
	    one1=one1->next;
	    
	}

	one1->next=two1;//joining
	
	two1->prev=one1;//joining
	ptr1=start;
	
	
	while(ptr1!=NULL)
	{
		printf("\n[%p][%p %d %p]",ptr1,ptr1->prev,ptr1->value,ptr1->next);
	    ptr1=ptr1->next;
	}
	
	return 0;
}
