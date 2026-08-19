#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n,ans;
int a[maxn];
int main(){
	cin>>T;
	while(T--){
        ans=0;
		cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(a[i]>0){
                ans+=a[i];
            }else{
                ans+=-a[i];
            }
        }
        cout<<ans<<endl;
	}
	return 0;
}