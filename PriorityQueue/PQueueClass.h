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
};
