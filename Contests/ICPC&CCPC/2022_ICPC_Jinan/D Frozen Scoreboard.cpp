#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int m;
void solve(){
    int fcnt,fpenalty;
    cin>>fcnt>>fpenalty;
    int cnt=0,penalty=0;
    vector<string> ans(m+1);
    vector<tuple<int,int,int>> v;
    for(int i=1;i<=m;i++){
        char ch;
        cin>>ch;
        if(ch=='.'){
            ans[i]=".";
            continue;
        }else if(ch=='+'){
            string s;
            cin>>s;
            int pos=s.find('/');
            int x=stoi(s.substr(0,pos));
            int y=stoi(s.substr(pos+1,s.size()));
            cnt++;
            penalty+=(x-1)*20+y;
            ans[i]="+ "+s;
        }else if(ch=='-'){
            string s;
            cin>>s;
            ans[i]="- "+s;
            continue;
        }else{
            int x,y;
            cin>>x>>y;
            v.push_back({x,y,i});
        }
    }
    int n=v.size();
    bool can=false;
    for(int i=0;i<(1<<n);i++){
        if(__builtin_popcount(i)!=fcnt-cnt){
            continue;
        }
        int _penalty=penalty,l=0,r=0;
        for(int j=0;j<n;j++){
            if((i>>j)&1){
                _penalty+=(get<1>(v[j])-get<0>(v[j]))*20;//1:total 0:after 4 hours
                l+=240;
                r+=299+20*(get<0>(v[j])-1);
            }
        }
        l+=_penalty,r+=_penalty;
        if(l>fpenalty||r<fpenalty){
            continue;
        }
        can=true;
        int delta=fpenalty-l;
        for(int j=0;j<n;j++){
            if((i>>j)&1){
                int tot=0;
                while(tot<get<0>(v[j])-1&&delta>=20){
                    tot++;
                    delta-=20;
                }
                int t=0;
                if(delta>=59){
                    delta-=59;
                    t=59;
                }else{
                    t=delta;
                    delta=0;
                }
                ans[get<2>(v[j])]="+ "+to_string(get<1>(v[j])-get<0>(v[j])+tot+1)+"/"+to_string(t+240);
            }else{
                ans[get<2>(v[j])]="- "+to_string(get<1>(v[j]));
            }
        }
        break;
    }
    if(!can){
        cout<<"No"<<endl;
    }else{
        cout<<"Yes"<<endl;
        for(int i=1;i<=m;i++){
            cout<<ans[i]<<endl;
        }
    }
}
int main(){
    int T;
    cin>>T>>m;
    while(T--){
        solve();
    }
    return 0;
}