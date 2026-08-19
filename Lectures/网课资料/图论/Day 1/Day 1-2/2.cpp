#include<iostream>

using namespace std;

struct ccf
{
	int money;
	ccf(){cout << "no money" << endl;}
	ccf(int x){
		money=x;
		cout << "much money" << endl;
	}
};

int main()
{
	ccf CCF[10];
}
