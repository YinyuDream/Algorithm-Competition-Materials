#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int T,n,cnt;
int a[maxn],b[maxn];
int main(){
	cin>>T;
	while(T--){
        cnt=0;
		cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        b[++cnt]=a[1];
        for(int i=2;i<=n;i++){
            if(a[i]>=a[i-1]){
                b[++cnt]=a[i];
            }else{
                b[++cnt]=a[i];
                b[++cnt]=a[i];
            }
        }
        cout<<cnt<<endl;
        for(int i=1;i<=cnt;i++)
            cout<<b[i]<<" ";
        cout<<endl;
	}
	return 0;
}