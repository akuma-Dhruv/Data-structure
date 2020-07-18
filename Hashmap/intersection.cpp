#include<bits/stdc++.h>
using namespace std;
void printInteraction(int*a,int *b,int as,int bs)
{
    unordered_map <int,bool> List1,List2;
    vector <int> h;
    for(int i=0;i<as;i++)
    {
        if(List1.count(a[i])==1)
        continue;
        List1[a[i]]=true;
    }
    for(int i=0;i<bs;i++)
    {
        if(List2.count(b[i])==1)
        continue;
        List2[b[i]]=true;
        h.push_back(b[i]);
    }
    for(int i=0;i<h.size();i++)
    {
        if(List1.count(h[i])==1)
        cout<<h[i]<<endl;
    }

}
    int main()
{
    int b[]={2,12,2,11,12,2,1,2,2,11,12,2,6};
    int a[]={2,1,22,12,4,5,2,6};
    printInteraction(a,b,(sizeof(a)/sizeof(int)),(sizeof(b)/sizeof(int)));
}

