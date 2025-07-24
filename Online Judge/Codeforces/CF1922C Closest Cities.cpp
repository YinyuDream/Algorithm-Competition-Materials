#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int T,n,k,ans;
int a[maxn],face[maxn],sum_a[maxn],sum_b[maxn];
int main(){
	cin>>T;
	while(T--){
        ans=0;
		cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i],sum_a[i]=sum_b[i]=0;
        sum_a[0]=sum_b[n+1]=0;
        for(int i=2;i<n;i++){
            if(a[i]-a[i-1]<a[i+1]-a[i]){
                face[i]=-1;
            }else{
                face[i]=1;
            }
        }
        face[1]=1,face[n]=-1;
        for(int i=1;i<=n;i++){
            sum_a[i]=sum_a[i-1];
            if(face[i]==-1){
                sum_a[i]+=a[i]-a[i-1]-1;
            }
            
        }
        for(int i=n;i>=1;i--){
            sum_b[i]=sum_b[i+1];
            if(face[i]==1){
                sum_b[i]+=a[i+1]-a[i]-1;
            }
        }
        cin>>k;
        for(int i=1,u,v;i<=k;i++){
            cin>>u>>v;
            ans=abs(a[u]-a[v]);
            if(u>v){
                ans-=sum_a[u]-sum_a[v];
            }else{
                ans-=sum_b[u]-sum_b[v];
            }
            cout<<ans<<endl;
        }
	}
	return 0;
}