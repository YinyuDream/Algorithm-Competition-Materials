#include<bits/stdc++.h>
using namespace std;
int T,l,r,max_lucky,ans;
int lucky(int x)
{
	int mx=0,mn=10;
	while(x){
		mx=max(mx,x%10);
		mn=min(mn,x%10);
		x/=10;
	}
	return mx-mn;
}
int main(){
	cin>>T;
	while(T--){
		max_lucky=ans=0;
		cin>>l>>r;
		for(int i=l;i<=min(r,l+100);i++){
			if(ans==0||lucky(i)>max_lucky){
				ans=i;
				max_lucky=lucky(i);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}