#include<iostream>
#include<queue>
using namespace std;
int main()
{
priority_queue<int> pq;
pq.push(44);
pq.push(7);
pq.push(66);
pq.push(21);
pq.push(12);
pq.push(8);
pq.push(89);
pq.push(11);

cout<<"Size: "<<pq.size()<<endl;
cout<<"Top: " <<pq.top()<<endl;
while(!pq.empty())
{
    cout<<pq.top()<<" ";
    pq.pop();
}
}
