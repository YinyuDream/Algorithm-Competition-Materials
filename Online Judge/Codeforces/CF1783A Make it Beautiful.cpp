#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int T,n;
int a[maxn];
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		if((a[n-1]==a[n]&&n==2)||a[1]==a[n]){
			puts("NO");
		}else{
			puts("YES");
			if(a[n-1]==a[n]){
				swap(a[n-1],a[1]);
			}
			for(int i=n;i;i--){
				cout<<a[i]<<" ";
			}
			puts("");
		}
	}
	return 0;
}