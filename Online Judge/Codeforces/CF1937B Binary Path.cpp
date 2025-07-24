#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n,ans,flag;
int a[maxn],b[maxn],c[maxn];
int main(){
	cin>>T;
	while(T--){
		cin>>n;
        for(int i=1;i<=n;i++){
            char ch;
            cin>>ch;
            while(ch!='0'&&ch!='1'){
                cin>>ch;
            }
            a[i]=ch-'0';
        }
        for(int i=1;i<=n;i++){
            char ch;
            cin>>ch;
            while(ch!='0'&&ch!='1'){
                cin>>ch;
            }
            b[i]=ch-'0';
        }
        c[1]=a[1],ans=1;
        for(int i=1;i<=n;i++){
            c[i+1]=b[i];
        }
        for(int i=2;i<=n;i++){
            if(a[i]==c[i]){
                ans++;
            }else if(a[i]<c[i]){
                c[i]=a[i];
                ans=1;
            }else{
                break;
            }
        }
        for(int i=1;i<=n+1;i++)
            cout<<c[i];
        cout<<endl;
        cout<<ans<<endl;
	}
	return 0;
}