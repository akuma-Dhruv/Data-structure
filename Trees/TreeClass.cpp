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
};
