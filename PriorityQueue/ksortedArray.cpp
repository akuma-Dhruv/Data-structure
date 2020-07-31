#include<iostream>
#include<queue>
using namespace std;
void Ksorted(int input[],int n,int k)
{
    priority_queue<int> pq;
    for(int i=0;i<k;i++)
    {
        pq.push(input[i]);
    }
    int j=0;
    for(int i=k;i<n;i++)
    {
        input[j]=pq.top();
        pq.pop();
        pq.push(input[i]);
        j++;
    }

    //till here all elements are in input array except last k elements


    while(!pq.empty())
    {
        input[j]=pq.top();
        pq.pop();
        j++;
    }
}
int main()
{
    int a[]= {10,12,6,9,7,4};
    int k=3;
    Ksorted(a,6,k);
    int i=0;
    while(i<6)
    {
    cout<<a[i]<<" ";
    i++;
    }
}
