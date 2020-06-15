#include<iostream>
using namespace std;

class Node{
public:
int data;
Node *next;
Node *prev;
Node(int d)
{
    data=d;
    next =NULL;
	prev= NULL;
}
};
Node* takeInput()
{
	int data;
	cin>>data;
	Node *head =NULL;
	Node *tail= NULL;
	Node *pre=NULL;
	while(data!=-1)
	{
	    Node *newNode= new Node(data);
		if(head==NULL)
		{
		    head=newNode;
            tail=newNode;
        }
		else
        {	tail->next=newNode;
			pre=tail;
			tail=tail->next;
			tail->prev = pre;
		}
		cin>>data;
	}
	head->prev=NULL;

	return head;
}
Node* insertNode(Node *head, int i,int data)
{
	Node *newNode= new Node(data);
	int count =0;
	Node *temp =head;
	if(i==0)
	{
		newNode->next=head;
		head->prev=newNode;
		head=newNode;
		head->prev =NULL;
		return head;
	}
	while (temp != NULL && count<i-1)
	{
		temp= temp->next;
		count++;
	}
	if(temp!=NULL)
	{
		Node *a =temp->next;
		temp-> next = newNode;
		newNode->next=a;
		a->prev= newNode;
		newNode->prev= temp;
	}
}
void print(Node *head)
{
        Node *temp = head;
		while(temp!=NULL)
    {
		cout << temp -> data << " ";
		temp = temp -> next;
	}
}
Node* InsertNodeRe(int i,int data,Node *head)
{		Node *newNode = new Node(data);
	if(head==NULL)
	return head;
	if(i==0)
	{
		newNode->next=head;
		head->prev=newNode;
		head=newNode;
		head->prev =NULL;
		return head;
	}
	else if(head!=NULL && i==1)
	{

		Node *a =head->next;
		head-> next = newNode;
		newNode->next=a;
		a->prev= newNode;
		newNode->prev= head;
	}
	else
		InsertNodeRe(i-1,data,head->next);



		return head;
}
Node* deleteNode(Node *head, int i)
{
	int count =0;
	Node *temp =head;
	if(i==0)
	{
		head=head->next;
		head->prev=NULL;
        delete temp;
		return head;
	}
	while (temp != NULL && count<i-1)
	{
		temp= temp->next;
		count++;
	}
	if(temp!=NULL)
	{
		Node *a =temp->next;
		Node*b =a-> next;
		temp->next=b;
		b->prev=temp;
        delete a;
	}
	return head;
}
Node *gettail(Node *head)
{
while(head->next!=NULL)
    {
		head= head->next;
	}
	return head;
}
void printRev(Node *head)
{ Node *tail=gettail(head);
Node*temp=tail;
    while(temp!=NULL)
    {
		cout << temp -> data << " ";
		temp = temp -> prev;
	}
}
int main()
{
	Node *head = takeInput();
	int i ,data;
	/*
	cin>>i>>data;
	head=InsertNodeRe(i,data,head);
	printRev(head);*/
	cin>>i;
	head=deleteNode(head,i);
	printRev(head);
}

