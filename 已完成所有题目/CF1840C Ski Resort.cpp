#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int T,n,k,q;
long long ans;
int a[maxn],l[maxn],r[maxn],top;
int main(){
	cin>>T;
	while(T--){
		top=ans=0;
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		a[0]=a[n+1]=0x7f7f7f7f;
		for(int i=0;i<=n;i++){
			if(a[i]>q&&a[i+1]<=q)l[++top]=i+1;
			if(a[i]<=q&&a[i+1]>q)r[top]=i;
		}
		for(int i=1;i<=top;i++){
			if(r[i]-l[i]+1>=k){
				int d=r[i]-l[i]+1;
				ans+=((long long)d-k+1)*(d-k+2)/2;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}