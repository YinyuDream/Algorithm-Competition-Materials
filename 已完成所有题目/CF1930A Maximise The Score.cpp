#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int T,n,ans;
int a[maxn];
int main(){
	cin>>T;
	while(T--){
        ans=0;
		cin>>n;
        for(int i=1;i<=n*2;i++){
            cin>>a[i];
        }
        sort(a+1,a+n*2+1);
        for(int i=1;i<=n;i++)
            ans+=a[i*2-1];
        cout<<ans<<endl;
	}
	return 0;
}