#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int T,n,ans;
int d[maxn],s[maxn];
int main(){
	cin>>T;
	while(T--){
		cin>>n;
        for(int i=1;i<=n;i++)
            cin>>d[i]>>s[i];
        ans=0x7f7f7f7f;
        for(int i=1;i<=n;i++){
            ans=min(ans,d[i]+(s[i]+1)/2-1);
        }
        cout<<ans<<endl;
	}
	return 0;
}