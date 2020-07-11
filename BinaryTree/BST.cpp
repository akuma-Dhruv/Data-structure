 #include<iostream>
 #include"BinaryTreeClass.h"
 #include"Linkedlist.h"
 #include<queue>
 using namespace std;
#define N NULL
#define BT BinaryTree<int>
#define L left
#define R right
#define D data
BinaryTree<int>* takeInputLevelWise()				///for input
{
    int rootdata;
    cout<<"Enter root data"<<endl;
    cin>>rootdata;
    if(rootdata==N)
      return N;
    BinaryTree<int>* root = new BinaryTree<int> (rootdata);
    queue <BT*> pending;
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
void printLevelWise(BT* root)		//to print tree
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

void searchBT(BT* root,int p)
{
    if(root==N)
    {
        cout<<"false"<<endl;
        return;
    }
    if(root->D==p)
    {
        cout<<"True"<<endl;
        return;
    }
    else if(root->D>p)
        searchBT(root->L,p);
    else if(root->D<p)
        searchBT(root->R,p);
    else
        cout<<"false"<<endl;
    return;
}
void printInRange(BT* root,int l,int u)
{

    if(root==N)
        return;
    if((root->D>=l) && (root->D<= u))
        cout<<root->D<<" ";
    if(root->D<u||root->D<l)
        printInRange(root->R,l,u);
    if (root->D>u||root->D>l)
        printInRange(root->L,l,u);
}
int maximum(BT* root)
{
    if(root==N)
        return INT_MIN;
        return(max (root->D,max(maximum(root->L),maximum(root->R))));

}
int minimum(BT* root)
{
    if(root==N)
        return INT_MAX;
        return(min (root->D,min(minimum(root->L),minimum(root->R))));

}
bool isbst(BT* root)
{
    if(root==N)
        return true;
    int l=maximum(root->left);
    int r= minimum(root->right);
    bool result = ((root->D > l) && (root->D <= r) && isbst(root->L) && isbst(root->R));
    return result;
    // but time complexity is poor
}
bool isBST2(BT* root, int min = INT_MIN, int max = INT_MAX) {
	if (root == N) {
		return true;
	}
	if (root->data < min || root->data > max) {
		return false;
	}
	bool isLeftOk = isBST2(root->left, min, root->data - 1);
	bool isRightOk = isBST2(root->right, root->data, max);
	return isLeftOk && isRightOk;
//better time complexity and approach

}
BT* constructBinaryTree(int *arr,int si,int ei)
{
    int mid=(ei+si)/2;
    //cout<<mid<<endl;
      if(ei<si)
        return N;
    BT* root= new BT(arr[mid]);
   root->L=constructBinaryTree(arr,si,mid-1);
    root->R=constructBinaryTree(arr,mid+1,ei);
    return root;
}
Node* gettail(Node *head)
{	//return tail of the given linked list
	Node *tail;
	Node *temp = head;
		while(temp != NULL)
    {   tail=temp;
		temp = temp -> next;
	}
	return tail;
}
Node* listFromTree(BT*root)
{
    if(root==N)
        return N;
    Node *temp=new Node(root->D);
    Node* tail;
    Node* head;
    Node* leftL=listFromTree(root->L);
    Node* rightL=listFromTree(root->R);
    if(leftL!=N)
  {

    tail=gettail(leftL);
        tail->next=temp;
        head=leftL;
  }
  else
    head = temp;
    if(rightL!=N)
        temp->next=rightL;
        return head;

}
vector<int>* getRootToNodePath(BT* root, int data) {
	if (root == NULL)
    {
		return NULL;
	}

	if (root->data == data) {
		vector<int>* output = new vector<int>();
		output->push_back(root->data);
		return output;
	}

	vector<int>* RightOutput ;
	 if(root->D<data)
	{
	     RightOutput = getRootToNodePath(root->right, data);
	    if(RightOutput!=N)
        {
            RightOutput->push_back(root->data);            return RightOutput;
        }
	}
	vector<int>* leftOutput ;
	if(root->D>data)
	{
    leftOutput = getRootToNodePath(root->left, data);
	    if(leftOutput!=N)
{
         leftOutput->push_back(root->data);
            return leftOutput;
}
}
else return N;
}
///4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1
///4 2 6 10 3 5 2 -1 -1 -1 -1 -1 -1 -1 -1
int main()
{
	//BT* root =takeInputLevelWise();
	//int p,u;
	//cout<<"enter range: ";
	//cin>>p>>u;
	//printInRange(root,p,u);
	int ar[]={1,2,3,4,5,6,7};
	int ei=sizeof(ar)/sizeof(int);
	//cout<<ei;
	BT* root=constructBinaryTree(ar,0,ei-1);
	//printLevelWise(root);
    //cout<<isbst(root);
	Node *h=listFromTree(root);
    h->printLL(h);
    cout<<endl;
    vector<int>*output =getRootToNodePath(root,5);
	for(int r=0;r<output->size();r++)
        cout<<output->at(r)<<" ";
	delete output;
	delete root;
}
