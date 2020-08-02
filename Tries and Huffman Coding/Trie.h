class Trie{
TrieNode *root;

public:
Trie()
{
root= new TrieNode('\0');
}
void insertWord(string word)
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
//for enduser
void insertWord(string word)
{
    insertWord(child,word.substr(1));
}

};
