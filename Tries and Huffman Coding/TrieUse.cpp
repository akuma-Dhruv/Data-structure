#include<iostream>
#include"trie.h"
using namespace std;
int main()
{
    Trie t;
    t.insertWord("dot");
    t.insertWord("boat");
    t.insertWord("born");
    t.insertWord("do");
    t.insertWord("bot");

    cout<<t.searchWord("do")<<endl;
	t.removeWord("born");
    cout<<t.searchWord("boat");


}
