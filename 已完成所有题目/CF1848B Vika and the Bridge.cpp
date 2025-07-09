#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int T,n,k,ans;
int a[maxn],p[maxn],mx[maxn],lmx[maxn];
int main(){
	cin>>T;
	while(T--){
		cin>>n>>k;
        for(int i=1;i<=k;i++)
            p[i]=mx[i]=lmx[i]=0;
        ans=0x7f7f7f7f;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(i-p[a[i]]-1>=mx[a[i]]){
                lmx[a[i]]=mx[a[i]];
                mx[a[i]]=i-p[a[i]]-1;
            }else if(i-p[a[i]]-1>lmx[a[i]]){
                lmx[a[i]]=i-p[a[i]]-1;
            }
            p[a[i]]=i;
        }
        for(int i=1;i<=k;i++){
            if(n-p[i]>=mx[i]){
                lmx[i]=mx[i];
                mx[i]=n-p[i];
            }else if(n-p[i]>lmx[i]){
                lmx[i]=n-p[i];
            }
        }
        for(int i=1;i<=k;i++){
            ans=min(ans,max(lmx[i],mx[i]/2));
        }
        cout<<ans<<endl;
	}
	return 0;
}