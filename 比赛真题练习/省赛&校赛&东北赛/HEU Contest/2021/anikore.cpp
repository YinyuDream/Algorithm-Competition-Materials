#include<bits/stdc++.h>
using namespace std;
int main(){
	for(int i=2;i<=2020;i++)
		if(2021%i==0){
			puts("No");
			return 0;
		}
	puts("Yes");
	return 0;
}