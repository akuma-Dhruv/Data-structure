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
        {
            tail=newNode;
        }
		cin>>data;
	}
	return head;
}
void insertNode(Node *head, int i,int data)
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
	insertNode(head,i,data);
}
