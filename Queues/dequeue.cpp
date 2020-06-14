#include<iostream>
using namespace std;
class deque
{
    int *data;
    int nI;
    int firstIndex;
    int capacity;
    int size;
public:
    deque()
    {
        data = new int [10];
        nI=0;
        firstIndex=0;
        size=0;
        capacity=10;

    }
	
	void insertRear(int element)
    {
         if(size==capacity)
        {
            cout<<"-1"<<endl;
            return;
        }
        data[nI]=element;
        nI= (nI+1)%capacity;
        if(firstIndex==-1)
        {
			firstIndex+=1;
        size++;
        i++;
		}
    }
		void deleteFront() {
		if(firstIndex==-1) {
			cout << "-1" << endl;
			return;
		}
		
		firstIndex = (firstIndex + 1) % capacity;
		size--;
		if(size == 0) {
			firstIndex = -1;
			nI = 0;
		}
	}
		void deleteRear() {
		if(firstIndex==-1) {
			cout << "-1" << endl;
			return;
		}
		nI--;
		size--;
		if(size == 0) {
			firstIndex = -1;
			nI = 0;
		}
	}
	int getfirstIndex() {
		if(firstIndex==-1) 
		{
			return 0;
		}
		return data[firstIndex];
	}
	int getRear() {
		if(firstIndex==-1) 
		{	
			return -1;
		}
		return data[nI-1];
	}