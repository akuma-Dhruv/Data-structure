#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
int main()
{
	//initilization
	unordered_map<string,int> mymap;
	//inserting & updating
	mymap ["abc"]=7;
	mymap ["jkl"]=15;
	//accessing
	cout<<mymap["abc"]<<endl;
	cout<<mymap.at("jkl")<<endl;
	//here comes the basic difference between them
	cout<<mymap["mno"]<<endl;		//it will create one with initial value of 0
	cout<<mymap.at("qpr")<<endl;	// it will give an exception
	//other functions
	cout<<mymap.count("abc")<<endl;	// will only return either 0 or 1
	cout<<mymap.size()<<endl;		//will return total number of keys present
	//delete
	mymap.erase("jkl");

}
