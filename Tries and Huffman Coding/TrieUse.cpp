#include<iostream>
#include"trie.h"
using namespace std;
int main()
{
    Trie t;
    t.insertWord("dot");
    t.insertWord("do");
    t.insertWord("bot");

    cout<<t.searchWord("dot");

}
