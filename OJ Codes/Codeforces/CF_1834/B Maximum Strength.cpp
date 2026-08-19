#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n;
string s1,s2;
int main(){
	cin>>T;
	while(T--){
		cin>>s1>>s2;
		if(s1.size()<s2.size())
			swap(s1,s2);
		s2.insert(s2.begin(),s1.size()-s2.size(),'0');
		int ans=0,flag=0;
		for(int i=0;i<s1.size();i++){
			if(flag==1){
				ans+=9;
			}else{
				if(s1[i]!=s2[i]){
					ans+=abs(s1[i]-s2[i]);
					flag=1;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}