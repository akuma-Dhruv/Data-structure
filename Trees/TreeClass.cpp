#include<vector>
using namespace std;
template <typename Y>
class TreeNode
{
public:
int data;
vector<TreeNode<Y>*>child;
TreeNode(Y data)
{
	this->data = data;
}
~ TreeNode()
{
    for(int i=0;i<child.size;i++)
        delete child[i];

}
};
