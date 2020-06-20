 #include<iostream>
 #include"BinaryTreeClass.h"
 #include<queue>
 using namespace std;
#define N NULL
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
int main()
{
BinaryTree<int>* root =takeInputLevelWise();

	print(root);
}
