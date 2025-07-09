#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int T,n,ans;
char s[maxn];
int main(){
	cin>>T;
	while(T--){
		cin>>n>>s+1;
		ans=n-1;
		for(int i=1;i<n-1;i++)
			if(s[i]==s[i+2])
				ans--;
		cout<<ans<<endl;
	}
	return 0;
}