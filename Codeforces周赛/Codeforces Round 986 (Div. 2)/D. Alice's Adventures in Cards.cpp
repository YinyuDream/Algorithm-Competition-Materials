#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
class BIT{
    public:
    int n;
    vector<int> a;
    void init(int _n){
        n=_n;
        a.clear();
        a.resize(n+1,0);
    }
    void add(int x,int v){
        for(int i=x;i<=n;i+=i&-i){
            a[i]=max(a[i],v);
        }
    }
    int query(int x){
        int res=0;
        for(int i=x;i;i-=i&-i){
            res=max(res,a[i]);
        }
        return res;
    }
};
struct node{
    int to,next,wt;
};
void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1),b(n+1),c(n+1);
    vector<int> posa(n+1),posb(n+1),posc(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    for(int i=1;i<=n;i++){
        posa[a[i]]=i;
        posb[b[i]]=i;
        posc[c[i]]=i;
    }
    vector<node> edge(n*6+1);
    vector<int> head(n+1);
    int cnt=0;
    auto add=[&](int u,int v,int w){
        edge[++cnt].to=v;
        edge[cnt].next=head[u];
        edge[cnt].wt=w;
        head[u]=cnt;
    };
    BIT bit1,bit2;
    bit1.init(n),bit2.init(n);
    for(int i=n;i>=1;i--){
        int pos1=posb[bit1.query(a[i]-1)];
        int pos2=posb[bit2.query(c[i]-1)];
        if(pos1)add(i,pos1,0);
        if(pos2)add(i,pos2,2);
        bit1.add(a[i],b[i]);
        bit2.add(c[i],b[i]);
    }
    bit1.init(n),bit2.init(n);
    for(int i=n;i>=1;i--){
        int pos1=posc[bit1.query(a[i]-1)];
        int pos2=posc[bit2.query(b[i]-1)];
        if(pos1)add(i,pos1,0);
        if(pos2)add(i,pos2,1);
        bit1.add(a[i],c[i]);
        bit2.add(b[i],c[i]);
    }
    bit1.init(n),bit2.init(n);
    for(int i=n;i>=1;i--){
        int pos1=posa[bit1.query(b[i]-1)];
        int pos2=posa[bit2.query(c[i]-1)];
        if(pos1)add(i,pos1,1);
        if(pos2)add(i,pos2,2);
        bit1.add(b[i],a[i]);
        bit2.add(c[i],a[i]);
    }
    vector<int> book(n+1),from(n+1),choose(n+1);
    auto bfs=[&](){
        queue<int> q;
        q.push(1);
        book[1]=1;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int i=head[u];i;i=edge[i].next){
                int v=edge[i].to;
                if(book[v]){
                    continue;
                }
                book[v]=1;
                from[v]=u;
                choose[v]=edge[i].wt;
                q.push(v);
            }
        }
    };
    bfs();
    if(!book[n]){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    vector<pair<int,int>> ans;
    for(int i=n;i!=1;i=from[i]){
        ans.push_back({choose[i],i});
    }
    reverse(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    string s="qkj";
    for(auto [x,y]:ans){
        cout<<s[x]<<" "<<y<<endl;
    }
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}