#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n,x;
int main(){
	cin>>T;
	while(T--){
		cin>>n;
        x=1;
        if(n==1){
            cout<<1<<endl;
        }else{
            while(x*2<=n){
                x*=2;
            }
            cout<<x<<endl;
        }
	}
	return 0;
}