#include<iostream>
#include<stack>
using namespace std;
int main()
{
	stack <int> s;
	s.push(14);
	s.push(13);
	s.push(15);
	s.push(2);
	s.push(1);
	s.push(6);
	s.push(4);
	s.push(44);
	s.push(21);
	cout<<s.top()<<endl;
	s.pop();
	s.pop();
	s.pop();
	s.pop();
	cout<<s.top()<<endl;
	cout<<s.size()<<endl;

	cout<<s.empty()<<endl;
}
