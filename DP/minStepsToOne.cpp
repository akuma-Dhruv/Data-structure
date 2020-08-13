#include<iostream>
using namespace std;
//basic approach
int stepsToOne (int n)
{
    //base case
if(n==1)
{
return 0;
}
//recursive call
int a = stepsToOne(n-1);
int b= INT_MAX,c=INT_MAX;
if(n%2==0)
 b = stepsToOne(n/2);
if(n%3==0)
c = stepsToOne(n/3);

int ans= min(a,min(b,c))+1;
return ans;
}


//memoization approach
//helper function
int stepsToOne_helper (int n,int *ans)
{
    //base case
if(n==1)
{
return 0;
}
//check if exist

if(ans[n]!=-1)
    return ans[n];

//recursive call
int a = stepsToOne(n-1);
int b= INT_MAX,c=INT_MAX;
if(n%2==0)
 b = stepsToOne(n/2);
if(n%3==0)
c = stepsToOne(n/3);
//getting final  answer
int d= min(a,min(b,c))+1;
//saving before returning
ans[n]=d;
return ans[n];
}

int stepsToOne2(int n)
{
    int *ans = new int [n+1];
    for(int i=0;i<=n;i++)
        ans[i]=-1;
    return stepsToOne_helper(n,ans);
}

//bottom-up
int getMinSteps ( int n )

{

int ans[n+1],i;

ans[1]=0;  // trivial case

for(int i=2;i<=n;i++)

{
ans[i]=1+ans[i-1];

if(i%2==0)
    ans[i]=min(ans[i],1+ans[i/2]);

if(i%3==0)
    ans[i]=min(ans[i],1+ans[i/3]);
}

return ans[n];

}



int main()
{
    int n;
    cin>>n;
    //cout<<stepsToOne2(n);
    cout<<getMinSteps(n);
}
