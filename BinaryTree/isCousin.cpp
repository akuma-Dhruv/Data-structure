 #include<iostream>
 #include"BinaryTreeClass.h"
 #include<queue>
 using namespace std;
 #define N NULL
#define BT BinaryTree<int>
#define L left
#define R right
#define D data
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
 int getdept(BinaryTree<int>* root,int e)
{
    if(root==NULL)
    {
     return 0;
    }
    if(root->data==e)
    {
        return 1;
    }
    int re=(getdept(root->left,e)+getdept(root->right,e));
    if(re!=0)
        re++;
    return re;

}
BinaryTree<int>* getparent(BinaryTree<int>* root,int e)
{
    if(root==N)
        return N;
        if(root->L->D==e||root->R->D==e)
        {
            return root;
        }
            //unable to handle recursion
            BT* LO=getparent(root->left,e);
            if(LO!=N)
                return LO;
            BT* RO=getparent(root->right,e);
                if(RO!=N)
                return RO;
            else
            return N;


}

int main()
{
    BinaryTree<int>*root=takeInputLevelWise();
    BT* g=getparent(root,4);
    cout<<g->D;


}
