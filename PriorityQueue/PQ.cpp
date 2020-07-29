#include<iostream>
#include"PQueueClass.h"
using namespace std;
int main()
{PQueue q;
q.Insert(990);
q.Insert(20);
q.Insert(30);
q.Insert(40);
q.Insert(50);
q.Insert(60);
cout<<q.getsize()<<endl;
cout<<q.isEmpty()<<endl;
cout<<q.getMin()<<endl;
cout<<q.removeMin();

}
