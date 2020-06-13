#include <iostream>
using namespace std;

class Node {
	public :
		int data;
		Node *prev;

		Node(int data) {
			this -> data = data;
			prev = NULL;
		}

		~Node() {
			delete prev;
		}
};

class Stack {
	Node *head;
	int sizze;

	public :

	Stack() {
		head=NULL;
		sizze =0;

	}

	int getSize() {
		return sizze;
	}

	bool isEmpty() {
	return sizze == 0;

	}

	void push(int input) {
		sizze++;
		Node *newNode;
		newNode = new Node(input);
		newNode->prev=head;
		head=newNode;

	}

	int pop() {
		Node * a;

		a= head;
		int d=a->data;
		head=head->prev;
		sizze--;
		delete a;
		return d;
	}

	int top() {
		return head->data;
	}

};
void reverse(Stack t1,Stack t2)
{
    while(!t1.isEmpty())
    {
        t2.push(t1.pop());
        cout<<t2.top()<<" ";
    }
}
int main()
{
Stack L;
L.push(4);
L.push(6);
L.push(5);
L.push(4);
L.push(9);
cout<<L.getSize()<<endl;
cout<<L.top()<<endl;
/*cout<<L.pop()<<endl;
cout<<L.pop()<<endl;
cout<<L.pop()<<endl;

cout<<L.isEmpty()<<endl;
*/
Stack K;
reverse(L,K);

}
