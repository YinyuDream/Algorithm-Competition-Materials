#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int T;
int n,k,d,w,remind,ans,last_time,last;
int t[maxn];
int main(){
	cin>>T;
	while(T--){
		remind=ans=0;
		cin>>n>>k>>d>>w;//n:病人数，k：疫苗每件个数，d：疫苗报废时间，w：病人等待时间
		for(int i=1;i<=n;i++){
			cin>>t[i];
		}
		for(int i=1;i<=n;i++){
			if(t[i]-last_time>d){
				remind=0;
			}
			if(remind==0){
				remind=k;
				last_time=t[i]+w;
				ans++;
			}
			if(t[i]-last_time<=d){
				remind--;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}