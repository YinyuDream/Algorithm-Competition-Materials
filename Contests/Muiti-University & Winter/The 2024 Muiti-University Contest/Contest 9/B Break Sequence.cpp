#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int p=998244353;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n+1),f(n+1),nxt(n+1);
    set<int>s;
    vector<int> pos[n+1];
    deque<pii>q[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pos[a[i]].push_back(i);
    }
    for(int i=1,x;i<=m;i++){
        cin>>x;
        s.insert(x);
    }
    for(int i=1;i<=n;i++){
        if(pos[i].size()<=1)
            continue;
        for(int j=0;j<pos[i].size()-1;j++){
            nxt[pos[i][j]]=pos[i][j+1];
        }
    }
    vector<int> cnt(n+1),book(n+1);
    f[0]=1;
    int tot=0;
    for(int i=1;i<=n;i++){
        cnt[a[i]]++;
        for(auto &j:q[a[i]]){
            int l=j.first,r=j.second;
            for(int k=l;k<=r;k++){
                book[k]--;
                if(!book[k]){
                    tot+=f[k-1];
                    tot%=p;
                }
            }
            int npos=nxt[r];
            for(int k=r+1;k<=npos;k++){
                if(!book[k]){
                    tot-=f[k-1];
                    tot%=p;
                }
                book[k]++;
            }
            j.first=r+1,j.second=npos;
        }
        if(s.count(cnt[a[i]])){
            q[a[i]].push_front({1,pos[a[i]][0]});
            for(int j=1;j<=pos[a[i]][0];j++){
                if(!book[j]){
                    tot-=f[j-1];
                    tot%=p;
                }
                book[j]++;
            }
        }
        if(!book[i]){
            tot+=f[i-1];
            tot%=p;
        }
        f[i]=tot%p;
    }
    cout<<((f[n]%p)+p)%p<<endl;
}