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
        int t1=1,t2=0;
        for(int i=1;i<=n;i++){
            if(a[i]%a[1]!=0){
                t2=i;
                break;
            }
        }
        if(t2==0)t2=n;
        bool flag=true;
        for(int i=1;i<=n;i++){
            if(a[i]%a[t1]!=0&&a[i]%a[t2]!=0){
                flag=false;
                break;
            }
        }
        if(flag)cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}