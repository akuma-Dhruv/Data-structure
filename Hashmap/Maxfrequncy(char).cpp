#include<iostream>
#include<unordered_map>
#include<string>

using namespace std;
char maxFrequency(char *a,int Size)
{int max=0,index=0;
    unordered_map <char,int> freq;
    for(int i=0;i<Size;i++)
    {

        if(freq.count(a[i])==0)
        {
            freq[a[i]]=1;

        }
        else
        freq[a[i]]++;
        if(max<freq[a[i]])
        {

         max=freq[a[i]];
         index =i;
        }
    }
    return a[index];
}
//2 12 2 11 12 2 1 2 2 11 12 2 6
//1 4 5
int main()
{
    char a[]={'s','f','r','r','s','s','A','y','u','w','q','r','r',';'};
    cout<<maxFrequency(a,(sizeof(a)/sizeof(char)));


}
