#include<bits/stdc++.h>
using namespace std;
vector<int> removeDublicate(int *a,int Size)
{
    vector<int> output;
    unordered_map <int,bool> List;
    for(int i=0;i<Size;i++)
    {
        if(List.count(a[i])==1)
        continue;

        List[a[i]]=true;
        output.push_back(a[i]);
    }
return output;
}
int main()
{
    int a[]={1,4,2,5,2,7,1,5,2,9,2,3,8};
    int si= sizeof(a)/sizeof(int);
    vector<int> g=removeDublicate(a,si);
    int i=0;
    while(i<g.size())
    {
        cout<<g.at(i)<<" ";
        i++;
    }
}
