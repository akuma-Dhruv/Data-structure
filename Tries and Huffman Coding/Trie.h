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
/// insert function 
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
// search function
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
       return res;
    }
    else
    {
        return false;
    }
}
//remove function 
void removeWord(TrieNode* root,string word)
{
	//base case
if(word.size()==0)
    {
        root->isTerminal =false;
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
		//word not found
		return;
	}
    //Recursive call
    removeWord(child,word.substr(1));
	//remove if useless
	if(child->isTerminal==false)
	{
		for(int i=0;i<26;i++)
		{
			if(child->children[i]!=NULL)
				return;
		}
		delete child;
		root->children[index]=NULL;
	}
}
//for end user
void insertWord(string word)
{
    insertWord(root,word);
}
bool searchWord(string word)
{
    return searchWord(root,word);
}
void removeWord(string word)
{
    removeWord(root,word);
}
//search alteranative

/*
bool searchWord(TrieNode *root,string word)
{//base case
if(word.size()==0)
    {
        return root->isTerminal;
    }
    //small calculation

    int index = word[0]-'a';
    TrieNode *child;
    if(root->children[index]!=NULL)
    {
       child = root->children[index];
    }
    else
    {
        return false;
    }
    //recursive call
    return searchWord(child,word.substr(1));
}
*/

};
