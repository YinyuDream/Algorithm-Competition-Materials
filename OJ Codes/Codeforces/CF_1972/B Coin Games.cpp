#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n;
char s[maxn];
int main(){
    cin>>T;
    while(T--){
        cin>>n>>(s+1);
        int cnt=0;
        for(int i=1;i<=n;i++)
            cnt+=(s[i]=='U');
        if(cnt&1)cout<<"YES";
        else cout<<"NO";
        cout<<endl;
    }
    return 0;
}