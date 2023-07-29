#include <stdio.h>
#include<malloc.h>

typedef struct node
{
  int val;
  struct node *next;
}node;


int main(void) {
  node *ptr,*ptr1,*s;
  s=NULL;
  int x;
  int n;
  printf("Enter the number of terms");
  scanf("%d",&n);
   for(int i=1;i<=n;i++)
    {
      printf("Enter new value which you want to insert :") ;
      scanf("%d",&x);
      ptr=(node *)malloc(sizeof(node));
      ptr->next=NULL;
      ptr->val=x;
      
      if(s==NULL)
      {
        s=ptr;
      }
      else
      {
        ptr1=s;
        if(ptr1->val>x)
        {
          ptr->next=s;
          s=ptr;
          
        }
        else
        {
        	
          while(ptr1->next!=NULL && ptr1->next->val<x)
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


  printf("In Ascending order\n");
  ptr=s;
  while(ptr!=NULL)
    {
      printf("[%p] {%d %p} \n",ptr,ptr->val,ptr->next);
      ptr=ptr->next;
    }
  
  return 0;
}