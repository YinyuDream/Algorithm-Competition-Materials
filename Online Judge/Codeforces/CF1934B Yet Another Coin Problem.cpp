#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n,cnt,ans,num;
int a[]={0,1,3,6,10,15};
int stdn[31]={0,1,2,1,2,3,1,2,3,2,1,2,2,2,3,1,2,3,2,3,2,2,3,3,3,2,3,3,3,4,2};
int main(){
	cin>>T;
	while(T--){
		cin>>n;
        if(n<=30){
            cout<<stdn[n]<<endl;
            continue;
        }
        num=n;
        cnt=num/a[5];
        num-=cnt*a[5];
        ans=cnt+stdn[num];

        num=n;
        cnt=num/a[5]-1;
        num-=cnt*a[5];
        ans=min(ans,cnt+stdn[num]);

        cout<<ans<<endl;
	}
	return 0;
}