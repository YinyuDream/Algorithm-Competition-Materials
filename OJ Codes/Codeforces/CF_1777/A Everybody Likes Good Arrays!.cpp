#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int T,n,cnt;
int a[maxn];
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		cnt=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<n;i++){
			if(a[i]%2!=a[i+1]%2){
				cnt++;
			}
		}
		cout<<n-cnt-1<<endl;
	}
	return 0;
}