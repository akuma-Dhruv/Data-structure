#include<iostream>
#include<tuple>
using namespace std;
int main()
{
    tuple<int,string,float>t1;
    t1= make_tuple(14,"void",17);
    cout<<get<2>(t1)<<" ";
    cout<<get<0>(t1)<<" ";
    cout<<get<1>(t1);


}
