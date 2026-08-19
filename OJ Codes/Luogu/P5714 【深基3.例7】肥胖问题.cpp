#include<iostream>
using namespace std;
double h,m,bmi;
int main()
{
	cin>>m>>h;
	bmi=m/(h*h);
	if(bmi<18.5)
	cout<<"Underweight";
	else if(bmi>=18.5&&bmi<24)
	cout<<"Normal";
	else
	cout<<bmi<<endl<<"Overweight";
	return 0;
} 