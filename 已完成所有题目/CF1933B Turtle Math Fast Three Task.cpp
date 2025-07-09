#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n,sum,cnt;
int a[maxn];
int main(){
	cin>>T;
	while(T--){
        sum=cnt=0;
		cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            a[i]%=3;
            sum=(sum+a[i])%3;
            if(a[i]==1){
                cnt++;
            }
        }
        if(sum%3==0){
            cout<<0<<endl;
            continue;
        }
        if(n==1){
            cout<<1<<endl;
            continue;
        }
        if(cnt>0){
            cout<<1<<endl;
            continue;
        }else{
            if(sum%3==2)cout<<1<<endl;
            else cout<<2<<endl;
            continue;
        }
	}
	return 0;
}