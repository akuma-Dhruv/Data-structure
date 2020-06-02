#include<iostream>
using namespace std;

class Node{
public:
int data;
Node *next;
Node(int d)
{
    data=d;
    next =NULL;
}
};
Node* takeInput()
{
	int data;
	cin>>data;
	Node *head =NULL;
	Node *tail= NULL;
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
			tail=tail->next;
            //tail=newNode;
        }
		cin>>data;
	}
	return head;
}
Node* insertNode(Node *head, int i,int data)
{
	Node *newNode= new Node(data);
	int count =0;
	Node *temp =head;
	if(i==0)
	{
		newNode ->next=head;
		head=newNode;
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
	}
}
Node* deleteNode(Node *head, int i)
{
	int count =0;
	Node *temp =head;
	if(i==0)
	{
		head=head->next;
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
        delete a;

	}
	return head;
}

void print(Node *head)
{
        Node *temp = head;
		while(temp != NULL)
    {
		cout << temp -> data << " ";
		temp = temp -> next;
	}
}

int main()
{
 Node *head = takeInput();
	print(head);
	int i,data;
/*	cin>>i>>data;
	head=insertNode(head,i,data);
	print(head);
*/	cin>>i;
	head=deleteNode(head,i);
	print(head);
}
