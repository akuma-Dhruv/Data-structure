#include<iostream>
using namespace std;
class arraystack
{
    int *data;
    int nI;
    int firstIndex;
    int capacity;
    int size;
public:
    arraystack(int s)
    {
        data = new int [s];
        nI=0;
        firstIndex=0;
        size=0;
        capacity=s;

    }
    int getSize()
    {
        return size;

    }
    bool isEmpty()
    {
        return size ==0;
    }
    void enqueue()
    {int i=0;
        while(i<capacity)
        {   int element;
        cin>>element;
            if(size==capacity)
        {
            cout<<"Queue is full"<<endl;
            return;
        }
        data[nI]=element;
        nI= (nI+1)%capacity;
        if(firstIndex==-1)
        {firstIndex+=1;
        }

        size++;
        i++;
    }
    }
	int front() {
		if(isEmpty()) {
			cout << "Queue is empty ! " << endl;
			return 0;
		}
		return data[firstIndex];
	}

	int dequeue() {
		if(isEmpty()) {
			cout << "Queue is empty ! " << endl;
			return 0;
		}
		int ans = data[firstIndex];
		firstIndex = (firstIndex + 1) % capacity;
		size--;
		if(size == 0) {
			firstIndex = -1;
			nI = 0;
		}
		return ans;
	}
};
int main()

{   int s;
cout<<"enter size for queue"<<"  ";
cin>>s;
     arraystack q(s);
    q.enqueue();
	/*q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	q.enqueue(50);
*/

	cout << q.front() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;

//	q.enqueue(60);
	cout << q.front() << endl;
	cout << q.getSize() << endl;
	cout << q.isEmpty() << endl;
}
