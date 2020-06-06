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
{
    int count=0;
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
	while (temp ->next!= NULL)
	{
		Node *a =temp->next;
	if(temp->data==a->data)
	{
		Node*b =a-> next;
		temp->next=b;
        delete a;

	}
	else
		temp= temp->next;
	}
	return head;
}
Node* gettail(Node *head)
{
	Node *tail;
	Node *temp = head;
		while(temp != NULL)
    {   tail=temp;
		temp = temp -> next;
	}
	return tail;

}
Node* midpoint(Node *head)
{
	Node *slow,*fast;
	slow=head;
	fast=head;
	if (head!=NULL)
    {
	while(fast!=NULL&&fast->next!= NULL)
	{
		slow=slow->next;
		fast = fast->next->next;
	}
	return slow;
    }
}
Node* mergeL(Node* h1, Node* h2)
{	Node *result=NULL;
    if (!h1)
        return h2;
    if (!h2)
        return h1;


    if (h1->data < h2->data) {
		result=h1;
        result->next = mergeL(h1->next, h2);

    }
    else {
		result=h2;
        result->next = mergeL(h1, h2->next);
    }
    return result;

}
void split(Node *head, Node **front, Node **back){
   Node *fast;
   Node *slow;
   slow = head;
   fast = head->next;
   while (fast != NULL) {
      fast = fast->next;
      if (fast != NULL) {
         slow = slow->next;
         fast = fast->next;
      }
   }
   *front = head;
   *back = slow->next;
   slow->next = NULL;
}
void mergeS(Node **head)
{
    Node *temp=*head;
	Node *a ;
	Node *b;

    if((temp== NULL) || (temp->next ==NULL))
    {

        return;
    }

	split(temp,&a,&b);
	mergeS(&a);
	mergeS(&b);
	*head=mergeL(a,b);

}

int main()
{
 Node *head = takeInput();
 //Node *head2 = takeInput();
//print(head);
int i,data;
/*	cin>>i>>data;
	head=insertNode(head,i,data);
	print(head);
*/
/*cin>>i;
	head=deleteNode(head,i);
	print(head);
*/
/*cin>>i;
cout<<findN(i,head);
*/
/*
cin>>i;
head=append(head,i);
print(head);
*/
//head =eliminate(head);
//print(head);
//head=reverseLL(head);
//print(head);
//midpoint(head);

/* head1=mergeL(head1,head2);
print(head1); */

mergeS(&head);
print(head);
}
