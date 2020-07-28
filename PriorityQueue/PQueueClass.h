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
};
