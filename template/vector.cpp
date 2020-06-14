#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector <int> v1{10,20,30,40,50,60};     //initializing while declaring
    vector <int> v2(10);        //declaring size of vector
    vector <int> v3(5,10);        //passing 5 as size of vector and 10  as element
                                    //vector v3 will have 10 at all 5 places
    vector <string> v4(5,"honest");
    //accessing elements


    cout<<v1[0]<<endl;    //similar to what we do in arrays
    //alternative way
    cout<<v1.at(4)<<endl;
    //capacity and size function
    cout<<v2.capacity()<<" "<<v2.size()<<endl;
    //push_back and pop function
    v3.push_back(77);       //will put 77 at very last position
    v1.pop_back();      //will delete 60 from last place
    //clear function
    v3.clear();     //will clean entire  vector
     // front and back
     cout<<v1.front()<<"   "<<v4.back()<<endl;

     //use of iterator
     vector <int>::iterator it=v1.begin();
     //insert function
     vi.insert(it+4,35);
}
