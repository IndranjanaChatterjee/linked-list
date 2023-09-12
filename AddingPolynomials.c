#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int value;
	int coeff;
	struct node *next;
}node;
void insert(node **s,int val,int coef)
{
	node *ptr,*ptr1;
	ptr=(node *)(malloc(sizeof(node)));
	ptr->coeff=coef;
	ptr->value=val;
	ptr->next=NULL;
	if((*s)==NULL)
	{
		(*s)=ptr;
	}
	else
	{
		ptr1=(*s);
		while(ptr1->next!=NULL)
		{
			ptr1=ptr1->next;
		}
		ptr1->next=ptr;
		
		
	}
}
node *add(node **poly1,node **poly2,node **result)
{
	node *p;
	(*result)=NULL;
	while((*poly1)!=NULL  &&  (*poly2)!=NULL)
	{
		if((*poly1)->coeff == (*poly2)->coeff)
		{
			insert(&(*result),((*poly1)->value+(*poly2)->value),(*poly1)->coeff);
			(*poly1)=(*poly1)->next;
			(*poly2)=(*poly2)->next;
		}
		else if((*poly1)->coeff > (*poly2)->coeff)
		{
			insert(&(*result),((*poly1)->value),(*poly1)->coeff);
			(*poly1)=(*poly1)->next;
			
		}
		else if((*poly1)->coeff < (*poly2)->coeff)
		{
			insert(&(*result),((*poly2)->value),(*poly2)->coeff);
			(*poly2)=(*poly2)->next;
			
		}
	}
	while((*poly1)!=NULL)
	{
		insert(&(*result),((*poly1)->value),(*poly1)->coeff);
		(*poly1)=(*poly1)->next;
		
	}
	while((*poly2)!=NULL)
	{
		insert(&result,((*poly2)->value),(*poly2)->coeff);
		(*poly2)=(*poly2)->next;
		
	}
	
}
void print(node **s)
{
	node *p;
	p=(*s);
	while(p!=NULL)
	{
		printf("\n[%p]{%d %d }",p,p->value,p->coeff);
		p=p->next;
	}
}
int main()
{
	node *p1,*p2,*hold,*hold1;
	p1=NULL;
	p2=NULL;
	insert(&p1,5,4);
	insert(&p1,3,2);
	insert(&p1,1,0);
	hold=p1;
	printf("\n");
	print(&hold);
	insert(&p2,4,4);
	insert(&p2,2,2);
	insert(&p2,1,1);
	hold=p2;
	print(&hold);
	printf("\n");
	hold=p1;
	hold1=p2;
	node *res;
	res=NULL;
	add(&hold,&hold1,&res);
	node *p;
	p=res;
	
	print(&p);
}
