#include<bits/stdc++.h>
using namespace std;
int n,a[21];
int main(){
	scanf("%d",&n);
	if(n%4!=1)puts("-1");
	else{
		for(int i=1;i<=n;i++){
			if(i%4==1||i%4==2)printf("0");
			else printf("1");
		}
	}
	return 0;
}