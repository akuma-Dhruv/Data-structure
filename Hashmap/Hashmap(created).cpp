#include<string>
#define N NULL
using namespace std;
template<typename V>
class MapNode{
public:
    string key;
    V value;
    MapNode next;
    //constructor
    MapNode(string key,V value)
    {
        this->key= key;
        this->value= value;
        next =N;
    }
    ~MapNode()
    {
         delete next;
    }
};
template<typename V>
class ourmap{
    MapNode<V>** buckets;
    int Count;
    int numbuckets;

    public:
        ourmap()
        {
            Count=0;
            numbuckets=5;
            buckets = new MapNode<V>*[numbuckets];
        for(int i=0;i<5;i++)
            buckets[i]=N;
        }
        ~ourmap()
        {
            for(int i=0;i<5;i++)
            delete buckets[i];
            delete[] buckets;
        }
    private:
    int getBucketIndex(string key)
    {
        int hashCode=0;
        int currentCoeff=1;
        for(int i=key.length()-1;i>=0;i++)
        {
            hashCode+=key[i]*currentCoeff;
            hashCode= hashCode% numbuckets; //just to make sure hashcode remain within the range

            currentCoeff*=37;
            currentCoeff = currentCoeff%numbuckets;
            }
            return hashCode%numbuckets;
    }
    public:

        int Size()
        {
            return Count;
        }
        void insert(string key,V value)
        {
           int bucketIndex=getBucketIndex(key);
           MapNode<V>* head = buckets[bucketIndex];
           while(head!=N)
           {
               if(head->key== key)
               {
                   head->value=value;
                   return;
               }
               head=head->next;
           }
           head= buckets[bucketIndex];
           MapNode<V>* node = new MapNode<V> (key,value);
           node->next= head;
           buckets[bucketIndex]=node;
           Count++;
        }
        V remove(string key)
        {
           int bucketIndex=getBucketIndex(key);
           MapNode<V>* head = buckets[bucketIndex];
           MapNode<V>* prev= N;
           while(head!=N)
           {
               if(head->key==key)
               {
                   if(prev==N)
                   {
                       buckets[bucketIndex]=head->next;

                   }else
                   prev->next=head->next;

                   V value = head->value;
                   head->next=N;
                   delete head;
                   Count--;
                   return value;
               }
                prev=head;
                head=head->next;
           }
           return 0;

        }


};
