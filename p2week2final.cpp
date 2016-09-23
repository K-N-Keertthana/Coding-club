/*two linked list start at different points and meet at a particular node 
and become common after that.We need to find the place where they meet by 
address or by printing out the value of that node.The time compexity should not be n^2*/
#include<iostream>
using namespace std;
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};

node *start[2],*temp,*prev,*curr[2];

void create();
void display();
int findlength(int i);
int findnode(int len1,int len2);

void create()
{
temp=new node;
temp->data=1;
temp->next=NULL;
start[0]=temp;
curr[0]=start[0];
temp=new node;
temp->data=2;
curr[0]->next=temp;
temp->next=NULL;
curr[0]=temp;
temp=new node;
temp->data=4;
curr[0]->next=temp;
temp->next=NULL;
curr[0]=temp;
temp=new node;
temp->data=7;
curr[0]->next=temp;
temp->next=NULL;
curr[0]=temp;
temp=new node;
temp->data=3;
curr[0]->next=temp;
temp->next=NULL;
curr[0]=temp;
prev=curr[0];
temp=new node;
temp->data=9;
curr[0]->next=temp;
temp->next=NULL;
curr[0]=temp;
temp=new node;
temp->data=6;
curr[0]->next=temp;
temp->next=NULL;
curr[0]=temp;
//linked list 2
temp=new node;
temp->data=2;
temp->next=NULL;
start[1]=temp;
curr[1]=start[1];
temp=new node;
temp->data=8;
curr[1]->next=temp;
temp->next=NULL;
curr[1]=temp;
curr[1]->next=prev;
display();
}

void display()
{
cout<<"\nThe linked list 1 elements are:\n";
curr[0]=start[0];
while(curr[0]!=NULL)
{
printf("%d ",curr[0]->data);
curr[0]=curr[0]->next;
if(curr[0]!=NULL)
printf("->");
}
cout<<"\nThe linked list 2 elements are:\n";
curr[1]=start[1];
while(curr[1]!=NULL)
{
printf("%d ",curr[1]->data);
curr[1]=curr[1]->next;
if(curr[1]!=NULL)
printf("->");
}
}
main()
{
	int l1,l2;
	create();
	l1=findlength(0);
	l2=findlength(1);
	cout<<"\nThe value at the meeting node is "<<findnode(l1,l2);
}

int findlength(int i)
{
 int length=0;
 curr[i]=start[i];
 while(curr[i]!=NULL)
 {
 length++;
 curr[i]=curr[i]->next;	
 }
 return length;	
}

int findnode(int len1,int len2)
{
	int diff,i;
	curr[0]=start[0];
	curr[1]=start[1];
	if(len1>len2)
	{
	diff=len1-len2;
    for(i=1;i<=diff;i++)
	curr[0]=curr[0]->next;
	}
	else if(len2>len1)
	{
	diff=len2-len1;
    for(i=1;i<=diff;i++)
	curr[1]=curr[1]->next;
	}
	else
	{
	}
	while(curr[0]!=NULL&&curr[1]!=NULL)
	{
		if(curr[0]->data==curr[1]->data)
		return curr[0]->data;
		else
		{curr[0]=curr[0]->next;
		 curr[1]=curr[1]->next;
		}
	}
}




