#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int T,n;
int ans[maxn];
int count(int x)
{
	int cnt=0;
	while(x){
		if(x%10!=0){
			cnt++;
		}
		x/=10;
	}
	return cnt;
}
int main(){
	cin>>T;
	for(int i=1;i<maxn;i++){
		if(count(i)==1){
			ans[i]=1;
		}
		ans[i]+=ans[i-1];
	}
	while(T--){
		cin>>n;
		cout<<ans[n]<<endl;
	}
	return 0;
}