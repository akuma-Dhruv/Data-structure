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
        cout<<"L"<<temp->L->data;
    }
    if(temp->R!=N)
    {
        pending.push(temp->R);
        cout<<" R"<<temp->R->data;
    }
    cout<<endl;

}
}
int CountNodes(BT* root)
{
    if(root==N)
    return 0;
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
int diameter(BT* root) {
	if (root == NULL) {
		return 0;
	}

	int option1 = height(root->left) + height(root->right);
	int option2 = diameter(root->left);
	int option3 = diameter(root->right);
	return max(option1, max(option2, option3));
}

pair<int,int> heightDiameter(BT* root)
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
int getmax(BT* root)
{
    if(root==N)
        return 0;
    int lmax=0,rmax=0,max=0;
    lmax=getmax(root->L);
    rmax=getmax(root->R);
    if(lmax>rmax)
        max=lmax;
    else
        max=rmax;
    if(root->D>max)
        max=root->data;
    return max;
}
int getmin(BT* root)
{
    if(root==N)
        return INT_MAX;
    int lmin=0,rmin=0,min;
    lmin=getmin(root->L);
    rmin=getmin(root->R);

    //calc part
    if(lmin<rmin)
        min=lmin;
    else
        min=rmin;
    if(root->D<min)
        min=root->D;
    return min;
}
int sumNodes(BT* root)
{
    if(root==N)
        return 0;
    int p=root->D;
    int lpart=sumNodes(root->L);
    int rpart=sumNodes(root->R);
return p+lpart+rpart;
}
void isIdentical(BT* root)
{
    if(root==N)
        return;
    int lheight=height(root->L);
    int rheight=height(root->R);
    int lcount=CountNodes(root->L);
    int rcount=CountNodes(root->R);
    if (lheight==rheight&&lcount==rcount)
        cout<<"True"<<endl;
    else
    cout<<"false"<<endl;

}
void levelorder(BT* root)
{
if (root==N)
    return;
queue <BT*>pending;
BT* point=new BT(-1);
pending.push(root);
pending.push(point);

while(!pending.empty())
{
    BT* temp=pending.front();
    cout<<temp->data<<" ";
    pending.pop();
    if(temp->L!=N)
    {
        pending.push(temp->L);
    }
    if(temp->R!=N)
    {
        pending.push(temp->R);
    }
    BT* check=pending.front();
    if(check->D==-1)
    {
    cout<<endl;
    pending.pop();
    if(!pending.empty())
    pending.push(point);
    }
}
}
int countLeaf(BT* root)
{
    if(root==N)
        return 0;
    int l=countLeaf(root->L);
    int R=countLeaf(root->R);
    if(root->left==N&&root->R==N)
    return 1+l+R;
    return l+R;
}
BT* deleteLeaf(BT* root)
{
    if(root==N)
        return 0;
    if(root->left==N&&root->R==N)
    {free(root);
    return N;}
  root->L=  deleteLeaf(root->L);
  root->R= deleteLeaf(root->R);
    return root;
}
void printleafs(BT* root)
{
    //will print all leaf nodes
    if(root==N)
        return;
    printleafs(root->L);
    printleafs(root->R);
    if(root->L==N&&root->R==N)
    cout<<root->data<<" ";
}

vector<int>* getRootToNodePath(BT* root, int data) {
	if (root == NULL) {
		return NULL;
	}

	if (root->data == data) {
		vector<int>* output = new vector<int>();
		output->push_back(root->data);
		return output;
	}

	vector<int>* leftOutput = getRootToNodePath(root->left, data);
	if (leftOutput != NULL) {
		leftOutput->push_back(root->data);
		return leftOutput;
	}

	vector<int>* rightOutput = getRootToNodePath(root->right, data);
	if (rightOutput != NULL) {
			rightOutput->push_back(root->data);
			return rightOutput;
	} else {
		return NULL;
	}
}
/***
BinaryTreeNode<int>* buildTreeHelper()
{}

///buid tree from preorder and postorder
***@incomplete
BinaryTreeNode<int>* buildTree()
{}
*/

///1 2 3 99 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
///10 9 4 -1 -1 5 8 -1 6 -1 -1 3 -1 -1 -1
///8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1

//driver function
int main()
{
int i=0;
while(i!=1)
{
BinaryTree<int>* root =takeInputLevelWise();

	//print(root);
	//cout<<endl<<"Number of nodes = "<<CountNodes(root)<<endl;
	//inorder(root);
//    cout<<endl;
    //mirror(root);
	//findNode(root,30);
	//cout<<height(root);
	//preorder(root);
	//cout<<getmax(root)<<endl;
	//cout<<getmin(root)<<endl;
	//printLevelWise(root);
	//cout<<sumNodes(root)<<endl;
	//isIdentical(root);
    //levelorder(root);
	//root=deleteLeaf(root);
	vector<int>*output =getRootToNodePath(root,5);
	for(int r=0;r<output->size();r++)
        cout<<output->at(r)<<" ";
	//printLevelWise(root);
    //levelorder(root);

	//printleafs(root);
	delete root;
cout<<"Enter 1 to exit::";
cin>>i;
}
}
