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
void print(Node *head) {
Node *temp = head;
		while(temp != NULL) {
		cout << temp -> data << " ";
		temp = temp -> next;
	}
}


int main(void)
{
 Node n1(2);
 Node n2(4);
 Node n3(6);
 Node n4(8);
 Node *head=&n1;

	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	print(head);


}
