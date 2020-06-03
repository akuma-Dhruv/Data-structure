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
{	int count=0;
        Node *temp = head;
		while(temp != NULL)
    {
		cout << temp -> data << " ";
		temp = temp -> next;
		count++;
	}
	//cout<<"\n"<<count;
}
int findN(int d,Node *head)
{
	int count=0;
	Node *temp = head;
	if (temp==NULL)
		return -1;
		while(temp != NULL)
    {
		if(temp -> data==d)
			return count;
		else
		temp = temp -> next;
		count++;
	}
	return -1;

}
Node* append(Node *head,int e)
{
	Node *tail;
	int count=0;
	Node *temp = head;
		while(temp != NULL)
    {   tail=temp;
		temp = temp -> next;
		count++;
	}
        if(e>count)
            return head;
	temp= head;
	//cout<<endl<<tail->data;  for debug purpose

	tail->next=temp;
	int i=0;
		while(temp != NULL&&i<count-e-1)
    {
		temp = temp -> next; i++;
	}
	Node *a=temp->next;
	temp->next=NULL;

	//cout<<temp->data; for debug
	head=a;
	delete a;
	delete temp;


	return head;


}
Node* eliminate(Node *head)
{

	Node *temp =head;
	Node *a;

	if(temp==NULL)
	{
		return head;
	}
	while (temp != NULL)
	{
		a =temp->next;
	if(temp->data==a->data)
	{
		Node*b =a-> next;
		temp->next=b;
        delete a;
	}
		temp= temp->next;
	}
	return head;
}
int main()
{
 Node *head = takeInput();
	//print(head);
	int i,data;
/*	cin>>i>>data;
	head=insertNode(head,i,data);
	print(head);
*/	/*cin>>i;
	head=deleteNode(head,i);
	print(head);
*/ /*cin>>i;
cout<<findN(i,head);
*/ /*
cin>>i;
head=append(head,i);
print(head);
*/
head =eliminate(head);
print(head);
}
