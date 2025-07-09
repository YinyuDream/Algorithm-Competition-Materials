#include<bits/stdc++.h>
using namespace std;
int T,n,x,mx,ans;
int main(){
	cin>>T;
	while(T--){
		cin>>x>>n;
        mx=sqrt(x)+1,ans=1;
        for(int i=1;i<=mx;i++){
            if(x%i==0){
                if(i>=n)ans=max(ans,x/i);
                if(x/i>=n)ans=max(ans,i);
            }
        }
        cout<<ans<<endl;
	}
	return 0;
}