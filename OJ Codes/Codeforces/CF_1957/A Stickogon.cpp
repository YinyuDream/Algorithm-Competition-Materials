#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=110;
int T,n;
int a[maxn],cnt[maxn];
int main(){
    cin>>T;
    while(T--){
        int num=0;
        cin>>n;
        memset(cnt,0,sizeof(cnt));
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++) cnt[a[i]]++;
        for(int i=1;i<=100;i++)
            num+=cnt[i]/3;
        cout<<num<<endl;
    }
    return 0;
}