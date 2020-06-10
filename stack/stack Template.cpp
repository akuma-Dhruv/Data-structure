#include<iostream>
using namespace std;
template <typename Z>
class stack
{
	Z *data;
	int index;
	int capacity;
	public:
	stack(int size)
	{
		data = new Z[size];
		index=0;
		capacity=size;
	}
	int size() {
		return index;
	}

	bool isEmpty()
{
		return index == 0;
	}

	void push(Z input) {
	// insert element
		if(index == capacity) {
			cout << "Stack full " << endl;
			return;
		}
		data[index] = input;
		index++;
	}

	Z pop() {
	// delete element
		if(isEmpty()) {
			cout << "Stack is empty " << endl;
			return -1;
		}
		index--;
		return data[index];
	}

	Z top() {
		if(isEmpty()) {
			cout << "Stack is empty " << endl;
			return -1;
		}
		return data[index - 1];
	}

};
int main()
{
stack<int> L(7);
L.push(7);
L.push(6);
L.push(5);
L.push(4);
L.push(9);
cout<<L.top();
cout<<L.pop();
cout<<L.pop();
cout<<L.pop();
cout<<L.isEmpty();
}
