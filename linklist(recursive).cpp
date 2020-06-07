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
{		Node *newNode = new Node(data);
	if(head==NULL)
	return head;
	if(i==0)
	{
		newNode ->next=head;
		head=newNode;
		return head;
	}
	else if(head!=NULL && i==1)
	{

		Node* a= head->next;
		head->next= newNode;
		newNode->next=a;
	}
	else
		InsertNode(i-1,data,head->next);



		return head;
}
Node* deleteNode(Node *head, int i)
{
	Node *temp =head;
	if(i==0)
		{
			head=head->next;
			delete temp;
			return head;
		}

	else if(temp!=NULL&&i==1)
	{
		Node *a =temp->next;
		Node*b =a-> next;
		temp->next=b;
        delete a;

	}
	deleteNode(head->next,i-1);
	return head;
}
Node* gettail(Node *head)
{
	if(head->next==NULL)
	{

		return head;
	}
	head=gettail(head->next);
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
Node* reverseL(Node *head)
{
	if(head==NULL )
	return head;
    if(head->next=NULL)
	return head;


	Node *a =reverseL(head->next);
	head->next->next=head;
	head->next=NULL;
	return a;
}



int main()
{
 Node *head = takeInput();
	/*print(head);
    cout<<"\nTotal Number of elements in list are "<<getcount(head)<<endl;
    int i,data;
	/*cin>>i>>data;
	head=InsertNode(i,data,head);
	print(head);
*//* 	cin>>i;
	head=deleteNode(head,i);
	print(head); */
	/* head= gettail(head);
	print(head); */
	head=reverseL(head);
	print(head);

}
