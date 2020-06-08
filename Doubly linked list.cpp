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
void print(Node *head)
{
        Node *temp = head;
		while(temp->next!=NULL)
    {
		//cout << temp -> data << " ";
		temp = temp -> next;
	}
	while(temp!=NULL)
    {
		cout << temp -> data << " ";
		temp = temp -> prev;
	}


}
int main()
{
	Node *head = takeInput();
	print(head);
}

