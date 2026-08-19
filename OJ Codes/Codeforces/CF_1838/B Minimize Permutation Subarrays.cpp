#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int T,n;
int a[maxn],pos[maxn],mx,mn,sum,l,r;
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			pos[a[i]]=i;
		}
		int ps1=pos[1],ps2=pos[2],psn=pos[n];
		if((psn-ps1)*(psn-ps2)<0)cout<<"1 1"<<endl;
		else{
			if(ps1<psn)cout<<max(ps1,ps2)<<" "<<psn<<endl;
			else cout<<psn<<" "<<min(ps1,ps2)<<endl;
		}
	}
	return 0;
}