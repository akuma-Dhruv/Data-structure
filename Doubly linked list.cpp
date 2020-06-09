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
Node *gettail(Node *head){

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
	cin>>i>>data;
	head=insertNode(head,i,data);
	printRev(head);
}

