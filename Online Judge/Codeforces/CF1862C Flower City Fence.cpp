#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int T,n;
int a[maxn],b[maxn];
int main(){
	cin>>T;
	while(T--){
		cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        if(a[1]>n){
            cout<<"No"<<endl;
            continue;
        }
        for(int i=n;i;i--){
            b[a[i]]=max(b[a[i]],i);
        }
        for(int i=n-1;i;i--){
            if(b[i]==0){
                b[i]=b[i+1];
            }
        }
        int flag=1;
        for(int i=1;i<=n;i++){
            if(b[i]!=a[i])flag=0;
        }
        if(flag)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
        for(int i=1;i<=n;i++)
            b[i]=0;
	}
	return 0;
}