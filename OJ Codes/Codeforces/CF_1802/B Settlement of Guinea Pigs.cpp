#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int T,n,ans,now,cnt,a[maxn];
int main(){
	cin>>T;
	
	while(T--){
		ans=cnt=now=0;
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				now++;
				cnt++;
			}else{
				if(cnt>0){
					now=cnt/2+1;
				}else{
					now=0;
				}
			}
			ans=max(ans,now);
		}
		cout<<ans<<endl;
	}
	return 0;
}