#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int T,n,ans,cnt;
int a[maxn];
int main(){
	cin>>T;
	while(T--){
		cin>>n;
        cnt=n;
        ans=0;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        sort(a+1,a+cnt+1);
        a[0]=0,a[++cnt]=1e9+1e5+10;
        cnt=unique(a+1,a+cnt+1)-a-1;
        //for(int i=1;i<=cnt;i++)
        //    cout<<a[i]<<" ";
        //puts("dwwwwwwww");
        for(int i=1;i<cnt;i++){
            int pos=upper_bound(a+1,a+cnt+1,a[i]+n-1)-a;
            ans=max(ans,pos-i);
        }
        cout<<ans<<endl;
	}
	return 0;
}