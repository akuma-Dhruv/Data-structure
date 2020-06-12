#include<iostream>
#include<array>
using namespace std;
int main()
{
    array <int,10> a1;

    a1.fill(10);
    a1[2]= 7;
    int i=0;
    while(i<10)
    {cout<<a1[i]<<" ";
    i++;}
    cout<<endl;
    cout<<a1.at(5)<<endl;
    cout<<a1.front()<<endl;
    cout<<a1.back()<<endl;
    cout<<a1.empty()<<endl;




}

