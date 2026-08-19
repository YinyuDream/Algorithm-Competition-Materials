#include<iostream>
#include<string>
#include<cctype>
using namespace std;
string s;
int main(){
	getline(cin,s);
	for(auto it=s.begin();it!=s.end();it++)
		*it=toupper(*it);
	cout<<s<<endl;
}
