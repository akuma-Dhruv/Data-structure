#include<iostream>
using namespace std;
int stepsToOne (int n)
{
if(n==1)
{
return 0;
}
int a = stepsToOne(n-1);
int b= INT_MAX,c=INT_MAX;
if(n%2==0)
 b = stepsToOne(n/2);
if(n%3==0)
c = stepsToOne(n/3);

int ans= min(a,min(b,c))+1;
return ans;
}
int main()
{
    int n;
    cin>>n;
    cout<<stepsToOne(n);
}
