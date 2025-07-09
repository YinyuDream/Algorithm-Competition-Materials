#include<bits/stdc++.h>
using namespace std;
const int maxn=4e5+10;
int T,n;
int a[maxn],b[maxn],posa[maxn],posb[maxn],cnt1,cnt2,ans;
int mxa[maxn],mxb[maxn];
int main(){
	cin>>T;
	while(T--){
		cnt1=cnt2=ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<=n;i++)
			cin>>b[i];
		for(int i=1;i<=n;i++){
			if(a[i]!=a[i-1])posa[++cnt1]=i;
			if(b[i]!=b[i-1])posb[++cnt2]=i;
		}
		
		posa[cnt1+1]=posb[cnt2+1]=n+1;
		for(int i=1;i<=n*2;i++)
			mxa[i]=mxb[i]=0;
		for(int i=1;i<=cnt1;i++){
			mxa[a[posa[i]]]=max(mxa[a[posa[i]]],posa[i+1]-posa[i]);
		}
		for(int i=1;i<=cnt2;i++){
			mxb[b[posb[i]]]=max(mxb[b[posb[i]]],posb[i+1]-posb[i]);
		}
		for(int i=1;i<=n*2;i++)
			ans=max(ans,mxa[i]+mxb[i]);
		cout<<ans<<endl;
	}
	return 0;
}