#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    vector<int> pos,pos_pos,pos_neg,ord(n+1);
    for(int i=0;i<n;i++){
        if(a[i]==0){
            ord[i]=pos.size();
            pos.push_back(i);
        }else if(a[i]>0){
            pos_pos.push_back(i);
        }else{
            pos_neg.push_back(i);
        }
    }
    vector<int> bk(pos.size());
    int tot=0;
    sort(pos_pos.begin(),pos_pos.end(),[&](int x,int y){
        return a[x]>a[y];
    });
    for(auto x:pos_pos){
        int now=lower_bound(pos.begin(),pos.end(),x)-pos.begin()-1;
        if(now<0){
            continue;
        }
        while(bk[now]==0&&now>=0&&tot<a[x]){
            bk[now]=1;
            tot++;
            now--;
        }
    }
    int ans=0;
    int cnt_0=0,cnt_1=0,val=0;
    for(int i=0;i<n;i++){
        if(a[i]==0){
            if(bk[ord[i]]==0){
                cnt_0++;
            }else{
                cnt_1++;
            }
        }else if(a[i]>0){
            val+=cnt_1>=a[i];
        }else{
            val+=cnt_0>=-a[i];
        }
    }
    ans=val;

    tot=0;
    bk.assign(pos.size(),0);
    sort(pos_neg.begin(),pos_neg.end(),[&](int x,int y){
        return a[x]<a[y];
    });
    for(auto x:pos_neg){
        int now=lower_bound(pos.begin(),pos.end(),x)-pos.begin()-1;
        if(now<0){
            continue;
        }
        while(bk[now]==0&&now>=0&&tot<-a[x]){
            bk[now]=1;
            tot++;
            now--;
        }
    }
    cnt_0=0,cnt_1=0,val=0;
    for(int i=0;i<n;i++){
        if(a[i]==0){
            if(bk[ord[i]]==0){
                cnt_0++;
            }else{
                cnt_1++;
            }
        }else if(a[i]>0){
            val+=cnt_0>=a[i];
        }else{
            val+=cnt_1>=-a[i];
        }
    }
    ans=max(ans,val);
    tot=0;
    bk.assign(pos.size(),0);
    for(int i=n-1;i>=0;i--){
        if(a[i]>0){
            int now=lower_bound(pos.begin(),pos.end(),i)-pos.begin()-1;
            if(now<0){
                continue;
            }
            while(bk[now]==0&&now>=0&&tot<a[i]){
                bk[now]=1;
                tot++;
                now--;
            }
        }
    }
    cnt_0=0,cnt_1=0,val=0;
    for(int i=0;i<n;i++){
        if(a[i]==0){
            if(bk[ord[i]]==0){
                cnt_0++;
            }else{
                cnt_1++;
            }
        }else if(a[i]>0){
            val+=cnt_1>=a[i];
        }else{
            val+=cnt_0>=-a[i];
        }
    }
    ans=max(ans,val);
    tot=0;
    bk.assign(pos.size(),0);
    for(int i=n-1;i>=0;i--){
        if(a[i]<0){
            int now=lower_bound(pos.begin(),pos.end(),i)-pos.begin()-1;
            if(now<0){
                continue;
            }
            while(bk[now]==0&&now>=0&&tot<-a[i]){
                bk[now]=1;
                tot++;
                now--;
            }
        }
    }
    cnt_0=0,cnt_1=0,val=0;
    for(int i=0;i<n;i++){
        if(a[i]==0){
            if(bk[ord[i]]==0){
                cnt_0++;
            }else{
                cnt_1++;
            }
        }else if(a[i]>0){
            val+=cnt_0>=a[i];
        }else{
            val+=cnt_1>=-a[i];
        }
    }
    ans=max(ans,val);

    cout<<ans<<endl;
}
int main(){
    int T=1;
    while(T--){
        solve();
    }
    return 0;
}