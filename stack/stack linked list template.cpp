#include <iostream>
using namespace std;
template<typename Z>
class Node {
	public :
		Z data;
		Node *prev;

		Node(Z data) {
			this -> data = data;
			prev = NULL;
		}

		~Node() {
			delete prev;
		}
};
template<typename Z>
class Stack {
	Node<Z> *head;
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

	void push(Z input) {
		sizze++;
		Node <Z> *newNode;
		newNode = new Node <Z>(input);
		newNode->prev=head;
		head=newNode;

	}

	Z pop() {
	if (isEmpty())
	return 0;
		Node <Z>* a;
		a= head;
		Z d=a->data;
		head=head->prev;
		sizze--;
		delete a;
		return d;
	}

	Z top() {
		return head->data;
	}

};
int main()
{
Stack <int>L;
L.push(4);
L.push(6);
L.push(5);
L.push(4);
L.push(9);
cout<<L.getSize()<<endl;
cout<<L.top()<<endl;
cout<<L.pop()<<endl;
cout<<L.pop()<<endl;
cout<<L.pop()<<endl;

cout<<L.isEmpty()<<endl;


}
