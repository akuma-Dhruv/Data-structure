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
		}
		cin>>data;
	}
	tail->next= head;           //tail is connected to head making a loop

	return head;
}
void print(Node *head)
{
        Node *temp = head;
		while(temp->next!=head)
    {
		cout << temp -> data << " ";
		temp = temp -> next;
	}
	cout<<temp->data;           //for the very last element
}


int main()
{
	Node *head = takeInput();
	print(head);
}

