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
Node* gettail(Node *head)
{	//return tail of the given linked list
	Node *tail;
	Node *temp = head;
		while(temp != NULL)
    {   tail=temp;
		temp = temp -> next;
	}
	return tail;
}
Node* reverseLL(Node *head)
{
    int count=0;
        Node *temp = head;
        Node*tail;
        if(temp==NULL)
	{
		return head;
	}
		while(temp != NULL)
    {   tail=temp;
		temp = temp -> next;
		count++;
	}
	int i=0;
	temp=head;
	Node*a,*b;
	while(i<count)
    {
        a=head->next;
        b=tail->next;
        tail->next=head;
        head->next=b;
        head=a;
        i++;
    }
    delete a,b,temp;
    return tail;
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
void increment (Node * head)
{
	Node *temp=gettail(head);
	int l= temp->data;
		int y=0;
	if(l==9)
	{
		temp->data=0;
		head=reverseLL(head);
		temp=head;
		temp=temp->next;
		y=temp->data;
		while(temp->data==9&&temp->next!=NULL)
		{
		temp->data=0;
		temp=temp->next;
		}
		temp->data++;
		head=reverseLL(head);
		print(head);
	}

else
	l++;
temp->data= l;

}

int main()
{
 Node *head = takeInput();
increment(head);
//head=reverseLL(head);
//print(head);
}
