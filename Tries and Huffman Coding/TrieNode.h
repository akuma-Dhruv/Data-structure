class TrieNode{
char data;
TrieNode **children;
bool isTerminal;

TrieNode(char data)
{
    this-> data =data;
    children = new TrieNode*[26]; //as maximum alphabet can be 26
    isTerminal= false;
}
};
