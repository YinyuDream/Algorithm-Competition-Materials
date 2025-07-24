#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int T,n,topu,topd;
int ans_l[maxn],ans_r[maxn],mn[maxn],mx[maxn],a[maxn],l[maxn],pos;
long long sum[maxn];
int main(){
	cin>>T;
	while(T--){
        topu=topd=pos=0;
		cin>>n;
        mn[0]=1e9;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            sum[i]=sum[i-1]+a[i];
            mn[i]=min(mn[i-1],a[i]);
            mx[i]=max(mx[i-1],a[i]);
            ans_l[i]=ans_r[i]=1e9;
            if(a[i]!=a[i-1])pos=i;
            l[i]=pos;
        }
        for(int i=2;i<=n;i++){
            if(sum[i-1]-a[i]<=0||(mn[i-1]==mx[i-1]&&a[i]>=a[i-1])){
                ans_l[i]=1e9;
                continue;
            }
            int pos=lower_bound(sum+1,sum+n+1,sum[i-1]-a[i])-sum-1;
            ans_l[i]=max(i-pos-1,i-l[i]+1);
        }
        cout<<l[4]<<"dw";
        reverse(a+1,a+n+1);
        pos=0;
        for(int i=1;i<=n;i++){
            sum[i]=sum[i-1]+a[i];
            mn[i]=min(mn[i-1],a[i]);
            mx[i]=max(mx[i-1],a[i]);
            if(a[i]!=a[i-1])pos=i;
            l[i]=pos;
        }
        for(int i=2;i<=n;i++){
            if(sum[i-1]-a[i]<=0||(mn[i-1]==mx[i-1]&&a[i]>=a[i-1])){
                ans_r[i]=1e9;
                continue;
            }
            int pos=lower_bound(sum+1,sum+n+1,sum[i-1]-a[i])-sum-1;
            ans_r[i]=max(i-pos-1,i-l[i]+1);
        }
        reverse(ans_r+1,ans_r+n+1);
        for(int i=1;i<=n;i++)
            cout<<(min(ans_l[i],ans_r[i])>n?-1:min(ans_l[i],ans_r[i]))<<" ";
        cout<<endl;
	}
	return 0;
}