#include<iostream>
#include<queue>
using namespace std;
void kSmallest(int a[],int k,int s)
{
priority_queue<int> pq;
for (int i=0;i<k;i++)
{
    pq.push(a[i]);
}
for(int i=k;i<s;i++)
{
    if(a[i]<pq.top())
    {
        pq.pop();
        pq.push(a[i]);
    }
}
while(!pq.empty())
{
cout<<pq.top()<<" ";
pq.pop();
}
}
int main()
{
    int a[]={3,5,6,7,2,9,1,0,44};

    kSmallest(a,2,sizeof(a)/sizeof(int));


    }



