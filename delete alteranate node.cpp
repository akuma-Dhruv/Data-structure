#include<iostream>
using namespace std;

class Node
{
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

Node* deleteNode(Node *head)
{
	int i=1;
	Node *temp =head;
	if(head==NULL)
		return head;
	}
	while (temp != NULL)
	{

	if(i%2==1)
	{
		Node *a =temp->next;
		Node*b =a-> next;
		temp->next=b;
        delete a;

	}
		temp= temp->next;
		i++;
	}

	return head;
}
void print(Node *head)
{		//print the Given linked list
    int count=0;
        Node *temp = head;
		while(temp != NULL)
    {
		cout << temp -> data << " ";
		temp = temp -> next;
		count++;
	}
}

int main()
{
 Node *head = takeInput();
 head=deleteNode(head);
 print(head);
 }
