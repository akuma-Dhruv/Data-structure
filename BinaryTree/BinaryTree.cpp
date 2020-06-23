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


//1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
//10 9 4 -1 -1 5 8 -1 6 -1 -1 3 -1 -1 -1
int main()
{
BinaryTree<int>* root =takeInputLevelWise();

	print(root);
	cout<<endl<<"Number of nodes = "<<CountNodes(root)<<endl;
	inorder(root);
    cout<<endl;
	printLevelWise(root);
	//findNode(root,30);
	cout<<height(root);
	delete root;
}
