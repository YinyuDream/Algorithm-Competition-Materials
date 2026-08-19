#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n,cnt;
int a[maxn],l[maxn],r[maxn];
int main(){
    cin>>T;
    while(T--){
        cnt=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            l[i]=r[i]=0;
            cnt+=(a[i]==0);
        }
        if(cnt!=1){
            cout<<"NO"<<endl;
            continue;
        }
        for(int i=1;i<=n;i++)
            l[i]=i-1;
        for(int i=1;i<n;i++)
            r[i]=i+1;
        r[n]=0;
        priority_queue<pair<int,int>> q;
        bool can=true;
        for(int i=1;i<=n;i++)
            q.push({a[i],i});
        while(q.size()>1){
            auto [val,pos]=q.top();
            q.pop();
            bool flag=false;
            flag|=l[pos]&&(a[pos]==a[l[pos]]+1);
            flag|=r[pos]&&(a[pos]==a[r[pos]]+1);
            flag|=l[pos]&&a[pos]&&a[pos]==a[l[pos]];
            flag|=r[pos]&&a[pos]&&a[pos]==a[r[pos]];
            if(flag){
                l[r[pos]]=l[pos];
                r[l[pos]]=r[pos];
            }else{
                can=false;
                break;
            }
        }
        if(q.top().first)
            can=false;
        cout<<(can?"YES":"NO")<<endl;
    }
    return 0;
}