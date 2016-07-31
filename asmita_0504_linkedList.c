/* Program: Linked List.
* Author: Asmita Ghimire.
* Date: July 31, 2016.
* Reference: Data structures using C and C++, Chapter 4.
*/

#include<stdio.h>
#include<stdlib.h>

struct node{
	int info;
	struct node *next;
};
typedef struct node *nodeptr;

nodeptr getnode();
void freenode(nodeptr);
void insertatfirst(nodeptr *,int);
int deletefromfirst(nodeptr *);
void displaylist(nodeptr);

int main()
{
	nodeptr list;
	list=NULL;
	
	insertatfirst(&list,1);
	insertatfirst(&list,2);
	insertatfirst(&list,3);
	insertatfirst(&list,4);
	displaylist(list);
	
	printf("The deleted item is %d\n",deletefromfirst(&list));
	printf("The deleted item is %d\n",deletefromfirst(&list));
	printf("The deleted item is %d\n",deletefromfirst(&list));
	printf("The deleted item is %d\n",deletefromfirst(&list));
	
}

nodeptr getnode()
{
return (nodeptr) malloc(sizeof(struct node));	
}

void freenode(nodeptr p)
{
	free(p);
}

void insertatfirst(nodeptr *p,int x)
{
	nodeptr q;
	q=getnode();
	q->info=x;
	q->next=*p;
	*p=q;
}

void displaylist(nodeptr p)
{
	while(p!=NULL)
	{
		printf("%d\n",p->info);
		p=p->next;
	}
}

int deletefromfirst(nodeptr *p)
{
	int a;	
	nodeptr q;
	q=*p;
	if(q==NULL)
	{
		printf("Underflow.\n");
		exit(0);
	}
	else
	{
		a=q->info;
		*p=q->next;
		free(q);
		return (a);
	}
}
