#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int T,n,mn;
int a[maxn];
int main(){
	cin>>T;
	while(T--){
        mn=0x7f7f7f7f;
		cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<n;i++)
            mn=min(mn,a[i+1]-a[i]);
        if(mn<0)
            cout<<"0"<<endl;
        else
            cout<<mn/2+1<<endl;
	}
	return 0;
}