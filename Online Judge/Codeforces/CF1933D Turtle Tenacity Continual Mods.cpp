#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n,pos,flag;
int a[maxn];
int main(){
	cin>>T;
	while(T--){
        flag=0;
		cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        sort(a+1,a+n+1);
        pos=1;
        while(a[pos+1]==a[1])pos++;
        if(pos==1){
            cout<<"YES"<<endl;
            continue;
        }
        if(pos==n){
            cout<<"NO"<<endl;
            continue;
        }
        for(int i=pos+1;i<=n;i++){
            if(a[i]%a[1]!=0){
                flag=1;
            }
        }
        if(flag==1){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
	}
	return 0;
}