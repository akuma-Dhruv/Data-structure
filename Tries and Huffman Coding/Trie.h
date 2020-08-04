#include"TrieNode.h"
#include<string>
using namespace std;
class Trie{
TrieNode *root;

public:
Trie()
{
root= new TrieNode('\0');
}
void insertWord(TrieNode *root,string word)
{//base case
if(word.size()==0)
    {
        root->isTerminal =true;
        return;
    }
    //small calculation

    int index = word[0]-'a';
    TrieNode *child;
    if(root->children[index]!=NULL)
    {
        child=root->children[index];
    }
    else
    {
        child = new TrieNode (word[0]);
        root->children[index] = child;
    }
    //Recursive call
    insertWord(child,word.substr(1));
}
bool searchWord(TrieNode *root,string word)
{//base case
if(word.size()==0)
    {
        if(root->isTerminal==true)
        return true;
        else
            return false;
    }
    //small calculation

    int index = word[0]-'a';
   bool res;
    if(root->children[index]!=NULL)
    {
       res = searchWord(root->children[index],word.substr(1));
    }
    else
    {
        return false;
    }
//this function will never work
///#Pure_illogical_code
}

//for enduser
void insertWord(string word)
{
    insertWord(root,word.substr(1));
}
bool searchWord(string word)
{
    return searchWord(root,word);
}

};
