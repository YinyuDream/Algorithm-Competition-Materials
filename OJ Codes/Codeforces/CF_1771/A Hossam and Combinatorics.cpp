#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int T,n,mx,mn,cmx,cmn;
int a[maxn];
int main(){
	cin>>T;
	while(T--){
		mx=cmx=cmn=0;
		mn=0x7f7f7f7f;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			if(a[i]<mn){
				mn=a[i];
				cmn=1;
			}else if(a[i]==mn){
				cmn++;
			}
		}
		for(int i=1;i<=n;i++){
			if(a[i]>mx){
				mx=a[i];
				cmx=1;
			}else if(a[i]==mx){
				cmx++;
			}
		}
		if(mx!=mn){
			cout<<1ll*cmx*cmn*2<<endl;
		}else{
			cout<<1ll*n*(n-1)<<endl;
		}
	}
	return 0;
}