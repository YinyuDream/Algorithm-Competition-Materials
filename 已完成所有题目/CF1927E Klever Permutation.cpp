#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int a[maxn];
int T,n,k,mn,mx;
int main(){
	cin>>T;
	while(T--){
		cin>>n>>k;
        mn=0,mx=n+1;
        for(int j=1;j<=k/2;j++){
            int mn_new=mn,mx_new=mx;
            for(int i=1;2*j-1+(i-1)*k<=n;i++){
                a[2*j-1+(i-1)*k]=mn+i;
                mn_new=mn+i;
            }
            for(int i=1;2*j+(i-1)*k<=n;i++){
                a[2*j+(i-1)*k]=mx-i;
                mx_new=mx-i;
            }
            mn=mn_new,mx=mx_new;
        }
        for(int i=1;i<=n;i++)
            cout<<a[i]<<" ";
        cout<<endl;
	}
	return 0;
}