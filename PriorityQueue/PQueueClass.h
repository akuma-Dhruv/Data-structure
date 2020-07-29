#include<vector>
using namespace std;

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
int getMin()
{if(isEmpty())
return 0;
else
return PQ[0];
}
void Insert(int elements)
{
    PQ.push_back(elements);
    int childIndex = PQ.size()-1;
    while(childIndex>0)
    {   int parentIndex = (childIndex-1)/2;
        if(PQ[childIndex]<PQ[parentIndex])
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
int removeMin()
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
        //looking for minimum element among 3
        int minIndex=parentIndex;
        if(PQ[minIndex]>PQ[lci])
        minIndex=lci;
        if(rci<PQ.size()&&PQ[minIndex]>PQ[rci])
        minIndex=rci;

        //swapping minimum element by parent
        int temp = PQ[parentIndex];
        PQ[parentIndex]=PQ[minIndex];
        PQ[minIndex]=temp;
        //updating index
        parentIndex=minIndex;
        lci= 2*parentIndex+1;
        rci= 2*parentIndex+2;
    }
return ele;
}

};
