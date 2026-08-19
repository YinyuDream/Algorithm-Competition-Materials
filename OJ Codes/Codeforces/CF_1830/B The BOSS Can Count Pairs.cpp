#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int T,n;
int a[maxn],b[maxn];
vector<int> num[maxn];
vector<int> vc;
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        cin>>b[i];
    for(int i=1;i<=n;i++)
        num[i].clear();
    for(int i=1;i<=n;i++)
        num[a[i]].push_back(b[i]);
    vc.clear();
    for(int i=1;i<=n;i++){
        if(num[i].size()==0)
            continue;
        sort(num[i].begin(),num[i].end());
        vc.push_back(i);
    }
    sort(vc.begin(),vc.end());
    ll ans=0;
    for(auto i=vc.begin();i!=vc.end();i++){
        ll tot=0;
        if((*i)*(*i)<=n*2){
            for(auto j:num[*i]){
                int val=(*i)*(*i)-j;
                int l=lower_bound(num[*i].begin(),num[*i].end(),val)-num[*i].begin();
                int r=upper_bound(num[*i].begin(),num[*i].end(),val)-num[*i].begin();
                tot+=r-l-(j==val);
            }
        }
        ans+=tot/2;
        for(auto j=next(i);(*i)*(*j)<=n*2&&j!=vc.end();j++){
            for(auto k:num[*i]){
                int val=(*i)*(*j)-k;
                int l=lower_bound(num[*j].begin(),num[*j].end(),val)-num[*j].begin();
                int r=upper_bound(num[*j].begin(),num[*j].end(),val)-num[*j].begin();
                ans+=r-l;
            }
        }
    }
    cout<<ans<<endl;
}
int main(){
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}