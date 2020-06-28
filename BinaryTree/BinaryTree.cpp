 #include<iostream>
 #include"BinaryTreeClass.h"
 #include<queue>
 using namespace std;
#define N NULL
#define BT BinaryTree<int>
#define L left
#define R right
#define D data


void print(BinaryTree<int>* root)
{
    if(root==N)
        return;
cout<<root->D<<":";
if (root->L!=N) {
		cout << "L" << root->L->D<<" ";
	}

	if (root->R!=N) {
		cout << "R" << root->R->D;
	}
	cout<<endl;
print(root->L);
print(root->R);

}
void inorder(BT* root)
{
    if(root==N)
        return;
    inorder(root->L);
    cout<<root->D<<" ";
    inorder(root->R);
}
BinaryTree<int>* takeInputLevelWise()
{
    int rootdata;
    cout<<"Enter root data"<<endl;
    cin>>rootdata;
    if(rootdata==N)
      return N;
    BinaryTree<int>* root = new BinaryTree<int> (rootdata);
    queue <BinaryTree<int>*> pending;
    pending.push(root);
    while(pending.size()!=0)
    {
        BinaryTree<int>* front = pending.front();
        pending.pop();
        cout<<"Enter left child of "<<front->D<<endl;
        int LChild;
        cin>>LChild;
        if(LChild!=-1)
        {
            BinaryTree<int>* child=new BinaryTree<int>(LChild);
            front->L=child;
            pending.push(child);
        }
        cout<<"Enter Right child of "<<front->D<<endl;
        int RChild;
        cin>>RChild;
        if(RChild!=-1)
        {
            BinaryTree<int>* child=new BinaryTree<int>(RChild);
            front->R=child;
            pending.push(child);
        }


    }

    return root;
}
void printLevelWise(BT* root)
{
if (root==N)
    return;
queue <BT*>pending;
pending.push(root);
while(!pending.empty())
{
    BT* temp=pending.front();
    cout<<temp->data<<":";
    pending.pop();
    if(temp->L!=N)
    {
        pending.push(temp->L);
        cout<<temp->L->data<<" ";
    }
    if(temp->R!=N)
    {
        pending.push(temp->R);
        cout<<temp->R->data;
    }
    cout<<endl;

}
}
int CountNodes(BT* root)
{
    if(root==N)
    {
        return 0;

    }
    return 1+ CountNodes(root->L)+CountNodes(root->R);
}
void findNode(BT* root,int num)
{
	if(root==N)
    {
        return;
    }
	int r;
r=root->D;
if(r==num)
	cout<<"true";
findNode(root->L,num);
findNode(root->R,num);
}

int height(BT* root)
{
    if(root==N)
	return 0;

int LD=height(root->L);
int RD=height(root->R);
if(RD>LD)
	return 1+RD;
else
	return 1+LD;
}
void mirror(BT* root)
{
    if(root==N)
        return;
    BT* temp;
    temp=root->L;
    root->L=root->R;
    root->R=temp;
    mirror(root->L);
    mirror(root->R);
}
void preorder(BT* root)
{
    if (root==N)
        return;
    cout<<root->data<<" ";
    preorder(root->L);
    preorder(root->R);
}
void postorder(BT* root)
{
    if (root==N)
        return;
    postorder(root->L);
    postorder(root->R);
    cout<<root->data<<" ";
}
int diameter(BinaryTree<int>* root) {
	if (root == NULL) {
		return 0;
	}

	int option1 = height(root->left) + height(root->right);
	int option2 = diameter(root->left);
	int option3 = diameter(root->right);
	return max(option1, max(option2, option3));
}

pair<int,int> heightDiameter(BinaryTree<int> *root)
{       ///better time Complexity
    pair<int,int> p;
    if(root==N)
    {
        p.first=0;
        p.second=0;
        return p;
    }
    pair<int,int> left = heightDiameter(root->L);
    pair<int,int> right = heightDiameter(root->R);
    int ld = left.second;
    int rd = right.second;
    int lh = left.first;
    int rh = right.first;
    int h=1+max(lh,rh);
    int d=max(lh+rh,max(rd,ld));
    p.first=h;
    p.second=d;
    return p;
}
/***
BinaryTreeNode<int>* buildTreeHelper()
{}

///buid tree from preorder and postorder
***@incomplete
BinaryTreeNode<int>* buildTree()
{}
*/

///1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
///10 9 4 -1 -1 5 8 -1 6 -1 -1 3 -1 -1 -1
///8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1

//driver function
int main()
{
BinaryTree<int>* root =takeInputLevelWise();

	//print(root);
	cout<<endl<<"Number of nodes = "<<CountNodes(root)<<endl;
	//inorder(root);
//    cout<<endl;
    //mirror(root);
	//findNode(root,30);
	//cout<<height(root);
	//preorder(root);
	pair<int,int>p=heightDiameter(root);
	cout<<"height "<<p.first<<endl;
	cout<<"Diameter "<<p.second<<endl;

	printLevelWise(root);
	delete root;
}
