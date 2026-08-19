#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n;
    cin>>n;
    auto ask=[&](int u,int v){
        cout<<"? "<<u<<" "<<v<<endl;
        cout.flush();
        int x;
        cin>>x;
        if(x==-1){
            exit(0);
        }
        return x;
    };
    vector<int> ans(n+1);
    auto output=[&](){
        cout<<"! ";
        for(int i=1;i<n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        cout.flush();
    };
    int val=0;
    for(int i=2;i<n;i++){
        if(ask(1,i)==0){
            val=i;
            break;
        }
    }
    if(val==2){
        for(int i=1;i<n;i++){
            ans[i]=i-1;
        }
        output();
        return;
    }
    vector<int> ban(val),mx(val);
    for(int i=1;i<val;i++){
        mx[i]=i;
    }
    ans[val]=1;
    mx[1]=val;
    int now=2;
    auto nxt=[&](int x){
        while(ban[x]){
            x++;
            if(x>=val){
                x=1;
            }
        }
        return x;
    };
    for(int i=val+1;i<n;i++){
        while(true){
            now=nxt(now);
            int x=ask(mx[now],i);
            if(x==1){
                ban[now]=1;
            }else{
                ans[i]=mx[now];
                mx[now]=i;
                now++;
                if(now>=val){
                    now=1;
                }
                break;
            }
        }
    }
    output();
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}