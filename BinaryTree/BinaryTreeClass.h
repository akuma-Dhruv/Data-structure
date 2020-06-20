template<typename T>
class BinaryTree
{
public:
    T data;
    BinaryTree* left;
    BinaryTree* right;
BinaryTree(T data)
{
    this->data=data;
    left=NULL;
    right=NULL;
}
~BinaryTree()
{
    delete left;
    delete right;
}
};
