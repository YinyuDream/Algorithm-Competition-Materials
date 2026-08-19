#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int T,n;
int a[maxn],sum[maxn],cnt[maxn];
long long ans;
int main(){
	cin>>T;
	while(T--){
		cin>>n;
        for(int i=0;i<=n;i++){
            sum[i]=cnt[i]=0;
        }
        ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            sum[a[i]]++;
        }
        cnt[0]=sum[0];
        for(int i=1;i<=n;i++){
            cnt[i]=sum[i]+cnt[i-1];
        }
        if(n<=2){
            cout<<0<<endl;
            continue;
        }
        for(int i=0;i<=n;i++){
            if(sum[i]>=3){
                ans+=1ll*sum[i]*(sum[i]-1)*(sum[i]-2)/6;
            }
            if(sum[i]>=2){
                ans+=1ll*sum[i]*(sum[i]-1)*cnt[i-1]/2;
            }
        }
        cout<<ans<<endl;
	}
	return 0;
}