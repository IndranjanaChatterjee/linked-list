#include<stdio.h>
#include<malloc.h>
	typedef struct node
	{
		int value;
		struct node *next;
		struct node *prev;
	}node;
	void insert_beg(int val,node **s)
	{
		node *ptr;		
		
			ptr=(node *)(malloc(sizeof(node)));
			
			ptr->value=val;
			ptr->next=NULL;
			ptr->prev=NULL;
			if((*s)==NULL)
			{
				
				(*s)=ptr;
			}
			else
			{
				ptr->next=(*s);
				(*s)->prev=ptr;
				(*s)=ptr;
				
			}
			
		}
		void insert_end(int val,node **s)
	{
		node *ptr,*ptr1;		
		
			ptr=(node *)(malloc(sizeof(node)));
			ptr1=(node *)(malloc(sizeof(node)));
			ptr->value=val;
			ptr->next=NULL;
			ptr->prev=NULL;
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
				ptr->prev=ptr1;
				ptr1->next=ptr;
				
			}
			
		}
		void insert_any(int val,node **s,int ele)
	{
		node *pt,*pt1;		
		
			pt=(node *)(malloc(sizeof(node)));
			pt1=(node *)(malloc(sizeof(node)));
			pt1->value=ele;
			pt1->next=NULL;
			pt1->prev=NULL;
			
			
			
			
				pt=*s;
				while(pt->next!=NULL && pt->value!=val)
				{
					pt=pt->next;
				}
				pt1->next=pt->next;
				pt1->prev=pt;
				pt->next->prev=pt1;
				pt->next=pt1;
				
				
				
			
			
		}
		void delete_beg(node **s)
		{
		    node *pp;
		    pp=(*s);
		    (*s)=pp->next;
		    (*s)->prev=NULL;
		    
		    
		    free(pp);
		    
		    
		    
		}
		void delete_end(node **s)
		{
		    node *pp,*hold;
		    hold=*s;
		    while(hold->next->next!=NULL)
		    {
		        hold=hold->next;
		    }
		    pp=hold->next;
		    hold->next=NULL;
		    
		    
		    free(pp);
		    
		    
		    
		}
		void delete_any(int v,node **s)
		{
		    node *pp,*hold;
		    hold=*s;
		    while(hold->next!=NULL && hold->next->value!=v)
		    {
		        hold=hold->next;
		    }
		    pp=hold->next;
		    hold->next=pp->next;
		    pp->next->prev=hold;
		    
		    
		    free(pp);
		    
		    
		    
		}
		void display(node **s)
		{
			node *point;
			point=*s;
		    while(point!=NULL)
			{
				printf("\n[%p]{%p %d %p}",point,point->prev,point->value,point->next);
				point=point->next;
			}
			
		}
		int main()
		{
			node *s,*p;
			s=NULL;
			int n,c=0;
			int choice;
			printf("\nEnter 1 to insert at the beginning and 2 to insert at the end:");
			scanf("%d",&choice);
			if(choice==1)
			{
				do
			{
			    printf("\nEnter the value to be entered:");
			    scanf("%d",&n);
			    insert_beg(n,&s);
			    printf("\nEnter 1 to terminate or 0 to continue:");
			    scanf("%d",&c);
			}while(c!=1);
			p=s;
			}
			else if(choice==2)
			{
					do
			{
			    printf("\nEnter the value to be entered:");
			    scanf("%d",&n);
			    insert_end(n,&s);
			    printf("\nEnter 1 to terminate or 0 to continue:");
			    scanf("%d",&c);
			}while(c!=1);
			p=s;
				
			}
			printf("Enter 1 to add values at any postion else enter -1:");
			int any;
			scanf("%d",&any);
			if(any==1)
			{
				int ele,ele1;
				printf("\nEnter the element after which to be added and the element to be added:\n");
				scanf("%d",&ele);
				scanf("%d",&ele1);
				insert_any(ele,&p,ele1);
			}
			p=s;//assigning the starting index
			display(&p);
			printf("\n");
			int dl;
			printf("Enter 1 to delete at begginning 2 to delete at the end and 3 to delete at any position:");
			scanf("%d",&dl);
			switch(dl)
			{
				case 1:
					delete_beg(&s);
					break;
				case 2:
					delete_end(&s);
					break;
				case 3:
					
					printf("Enter the value to be deleted:");
					int d;
					scanf("%d",&d);
					delete_any(d,&s);
					
					break;
				default:
					printf("Enter proper choice!!");
			}
			
			
			printf("\n");
			p=s;//assigning the starting index
			
			display(&p);
			
		    return 0;
		}
		
		
		
	