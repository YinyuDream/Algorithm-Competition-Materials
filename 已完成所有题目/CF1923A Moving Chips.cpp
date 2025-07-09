#include<bits/stdc++.h>
using namespace std;
const int maxn=110;
int T,n;
int a[maxn],l[maxn],r[maxn],cnt,ans;
int main(){
	cin>>T;
	while(T--){
        cnt=0;
		cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        a[n+1]=0;
        for(int i=0;i<=n;i++){
            if(a[i]==0&&a[i+1]==1){
                l[++cnt]=i+1;
            }
            if(a[i]==1&&a[i+1]==0){
                r[cnt]=i;
            }
        }
        if(cnt==1||cnt==0){
            cout<<0<<endl;
            continue;
        }
        ans=0;
        for(int i=cnt;i>1;i--){
            ans+=l[i]-r[i-1]-1;
        }
        cout<<ans<<endl;
	}
	return 0;
}