#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n;
int a[maxn];
int main(){
	cin>>T;
	while(T--){
		cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        sort(a+1,a+n+1);
        cout<<a[n]-a[1]+a[n]-a[2]+a[n-1]-a[1]+a[n-1]-a[2]<<endl;
	}
	return 0;
}