#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int T,n,flag;
int a[maxn];
int main(){
	cin>>T;
	while(T--){
		flag=0;
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<=n;i++){
			if(a[i]<=i){
				puts("YES");
				flag=1;
				break;
			}
		}
		if(!flag){
			puts("NO");
		}
	}
	return 0;
}