#include<iostream>
using namespace std;
//dynamic programing (bottom-up)
int fibo2(int n)
{
    int *ans= new int [n+1];

    ans[0]=0;
    ans[1]=1;

    for(int i =2;i<=n;i++)
        ans[i]=ans[i-1]+ans[i-2];
    return ans[n];

}
//memoization(top down)
int fibo_helper(int n,int *ans)
{
    if(n<=1)
        return n;
    if(ans[n]!=-1)
        return ans[n];
    //if doesn't exist then call recursion
    int a= fibo_helper(n-1,ans);
    int b= fibo_helper(n-2,ans);

    //saving ans for future use
    ans[n]=a+b;

    return ans[n];


}
int fibo(int n)
{
    int *Ex = new int (n+1);
    for (int i=0;i<n+1;i++)
    {
        Ex[i]=-1;
    }
    return fibo_helper(n,Ex);
}
int main()
{
    cout<<fibo2(25);

}
