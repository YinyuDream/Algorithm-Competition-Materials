#include<bits/stdc++.h>
using namespace std;
const int maxn=110;
int T,n,k,sum;
int a[maxn],b[maxn],ans[maxn];
int main(){
	cin>>T;
	while(T--){
		sum=0;
		memset(a,0,sizeof a);
		memset(b,0,sizeof b);
		memset(ans,0,sizeof ans);
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			if(i%k==0)a[i]=i/k;
			else a[i]=i/k+1;
		}
		for(int i=1;i<=n;i++){
			if((n-i+1)%k==0)b[i]=(n-i+1)/k;
			else b[i]=(n-i+1)/k+1;
		}
		for(int i=1;i<=n;i++){
			if(a[i]!=a[i-1]){
				ans[i]=1;
				if(i>n/2+n%2)
					break;
			}
		}
		for(int i=n;i>n/2;i--){
			if(b[i]!=b[i+1]&&!ans[i])
				ans[i]=1;
			else if(ans[i])break;
		}
		for(int i=1;i<=n;i++)
			sum+=ans[i];//,cout<<a[i]<<" ";
		cout<<sum<<endl;
	}
	return 0;
}