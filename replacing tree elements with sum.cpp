#include<iostream>
using namespace std;

class bst
{
public:
 struct treenode
 {
 int value;
 treenode *right;
 treenode *left;
 };
 treenode *root;
 bst()
 {
 root=NULL;
 }
 void insert(int n);
 void deletenode(int num);
 void deletion(int,treenode *&);
 void makedeletion(treenode *&);
 void traverse();
 void inorder(treenode *);
 void replace(treenode *);
 void doreplace();
 };

void bst::insert(int n)
{
int flag=0;
treenode *temp,*nptr;
temp=new treenode;
temp->value=n;
temp->left=NULL;
temp->right=NULL;
if(root==NULL)
{
root=temp;
}
else
{
nptr=root;
while(nptr!=NULL)
{
if(n<nptr->value)
  {
    if(nptr->left)
     nptr=nptr->left;
    else 
     {nptr->left=temp;
     break;}
  }
else if(n>nptr->value)
  {
     if(nptr->right)
     nptr=nptr->right;
    else
     {nptr->right=temp;
     break;}
  }
else
 {
  cout<<"Duplicate value found ";
  flag=1;
  break;
 }
}
}
if(flag==0)
{
cout<<"\nNode inserted.\nThe tree in inorder traversal is \n";
inorder(root);
}
else
cout<<"\nNode not inserted.";
}

void bst::deletenode(int num)
{
if(root)
deletion(num,root);
else
cout<<"\nThe tree is empty";
}

void bst::deletion(int num,treenode *&nptr)
{
  if(nptr!=NULL)
  {
  if(num==nptr->value)
   makedeletion(nptr);
 else if(num<nptr->value)
   deletion(num,nptr->left);
 else
   deletion(num,nptr->right);
  }
  else
  cout<<"\nElement not found";
}

void bst::makedeletion(treenode *&nptr)
{
  treenode * temp;
  if(nptr==NULL)
     cout<<"\nCannot delete empty node";
  else if(nptr->right==NULL)
     {
      temp=nptr;
      nptr=nptr->left;
      delete (nptr);
      cout<<"\nNode deleted successfully.\nThe tree in inorder traversal is \n";
      inorder(root);
     }
  else if(nptr->left==NULL)
     {
     temp=nptr;
     nptr=nptr->right;
     delete (nptr);
     cout<<"\nNode deleted successfully.\nThe tree in inorder traversal is \n";
     inorder(root);
     }
  else
     {
     temp=nptr->right;
     while(temp->left)
     temp=temp->left;
     nptr->value=temp->value;
     delete (temp);
     cout<<"\nNode deleted successfully.\nThe tree in inorder traversal is \n";
     inorder(root);
     }
}

void bst::traverse()
{
			inorder(root);
}

void bst::inorder(treenode *nptr)
{
   if(nptr)
    {
	inorder(nptr->left);
	cout<<nptr->value<<"\n";
	inorder(nptr->right);
	}
	if(root==NULL)
	cout<<"\nTree is empty";	
}

int sum=0;

void bst::replace(treenode *root)
{
	if(root)
	{
		replace(root->right);
		root->value+=sum;
		sum=root->value;
		replace(root->left);
	}
}

void bst::doreplace()
{   
    if(root)
	{
	replace(root);
	cout<<"\nReplace done successfully.\nThe inorder traversal is \n";
	inorder(root);
    }
	else
	cout<<"\nTree is empty";
}

main()
{
	int choice=0,n;
	bst b;
	cout<<"      BINARY SEARCH TREE   ";
	while(choice!=5)
	{
		cout<<"\n\nYour choices are:\n1.Insertion\n2.Deletion\n3.Inorder Traversal\n4.Replace\n5.Exit";
		cout<<"\nEnter choice ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"Enter the number to insert ";
				cin>>n;
				b.insert(n);
				break;
			case 2:
				cout<<"Enter the element to delete ";
				cin>>n;
				b.deletenode(n);
			    break;
			case 3:
				b.traverse();
				break;
			case 4:
				b.doreplace();
			    break;
			case 5:
				break;
			default:
				cout<<"\nInvalid choice ";
		}
	}
}


