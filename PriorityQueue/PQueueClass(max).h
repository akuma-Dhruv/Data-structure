#include<vector>
using namespace std;
//maximum priority queue
class PQueue
{
vector <int> PQ;
    public:
PQueue(){

}
bool isEmpty()
{
return PQ.size()==0;
}
int getsize()
{
return PQ.size();
}
int getMax()
{if(isEmpty())
return 0;
else
return PQ[0];
}
void Insert(int element)
{
PQ.push_back(element);
    int childIndex = PQ.size()-1;
    while(childIndex>0)
    {   int parentIndex = (childIndex-1)/2;
        if(PQ[childIndex]>PQ[parentIndex])
        {
            //swap
            int temp = PQ[childIndex];
            PQ[childIndex]=PQ[parentIndex];
            PQ[parentIndex]= temp;
        }
        else
            break;
        childIndex =parentIndex;
    }
}
int removeMax()
{
    int ele = PQ[0];
    //swap
    int temp = PQ[0];
    PQ[0]=PQ[PQ.size()-1];
    PQ[PQ.size()-1]=temp;

    PQ.pop_back();

    //down_hepify
    int parentIndex = 0;
    int lci= 2*parentIndex+1;
    int rci=2*parentIndex+2;
    while(lci<PQ.size())
    {
        //looking for maximum element among 3
        int maxIndex=parentIndex;
        if(PQ[maxIndex]<PQ[lci])
        maxIndex=lci;
        if(rci<PQ.size()&&PQ[maxIndex]<PQ[rci])
        maxIndex=rci;
        if(maxIndex==parentIndex)
            break;
        //swapping minimum element by parent
        int temp = PQ[parentIndex];
        PQ[parentIndex]=PQ[maxIndex];
        PQ[maxIndex]=temp;
        //updating index
        parentIndex=maxIndex;
        lci= 2*parentIndex+1;
        rci= 2*parentIndex+2;
    }
return ele;
}
};
