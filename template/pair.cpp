#include<iostream>
using namespace std;
class book
{
string name;
int price;
string author;
public:
   void setbook(string name,int p,string aut)
   {
       this-> name=name;
       price = p;
       author=aut;
   }
   void showdetail()
   {
    cout<<name<<" by "<<author<<" for Rs"<<price;
   }
};
int main()
{   book b;
	pair <string,int> p1;
	pair <int,int> p2;
	pair <string,float> p3;
	b.setbook("Engineering Mathematics",300,"Dr.Deepak Gupta");
	pair <string,book> c1;
	p1=make_pair("Aryan ",18);
	p2= make_pair(12,15);
	c1= make_pair("BOOK",b);
	p3 = make_pair("Effective code",270.50);
	//accessing values
	cout<<p1.first<<" "<<p1.second<<endl;//first to access first value second for 2nd value
	cout<<p2.first<<" "<<p2.second<<endl;
	cout<<p3.first<<" "<<p3.second<<endl;
	cout<<c1.first<<" ";
	book b2 = c1.second;
	b2.showdetail();



	}
