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
	return head;
}
Node* InsertNode(int i,int data,Node *head)
{  Node* temp =head;
	if(head==NULL)
	return head;
	else if(head!=NULL && i==0)
	{
		Node *newNode = new Node(data);
		newNode->next=temp;
		temp=newNode;
        //return head;
	}
	else
		InsertNode(i-1,data,temp->next);
		return head;
}
int getcount(Node *head)
{
	if(head==NULL)
	{
		return 0;
	}
	else
		return 1+getcount(head->next);
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
    //cout<<"\nTotal Number of elements in list are "<<getcount(head);
    int i,data;
	cin>>i>>data;
	head=InsertNode(i,data,head);
	print(head);
}
