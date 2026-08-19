#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
class fraction{
    private:
        ll a,b;
    public:
        fraction(ll a=0,ll b=1){
            this->a=a;
            this->b=b;
            ll g=__gcd(a,b);
            this->a/=g;
            this->b/=g;
        }
        fraction operator+(const fraction &x){
            return fraction(a*x.b+b*x.a,b*x.b);
        }
        fraction operator-(const fraction &x){
            return fraction(a*x.b-b*x.a,b*x.b);
        }
        fraction operator*(const fraction &x){
            return fraction(a*x.a,b*x.b);
        }
        fraction operator/(const fraction &x){
            return fraction(a*x.b,b*x.a);
        }
        bool operator<(const fraction &x){
            return a*x.b<x.a*b;
        }
        bool operator>(const fraction &x){
            return a*x.b>x.a*b;
        }
        bool operator==(const fraction &x){
            return a*x.b==x.a*b;
        }
        bool operator!=(const fraction &x){
            return a*x.b!=x.a*b;
        }
        bool operator<=(const fraction &x){
            return a*x.b<=x.a*b;
        }
        bool operator>=(const fraction &x){
            return a*x.b>=x.a*b;
        }
        void print(){
            cout<<a<<"/"<<b<<endl;
        }
};
struct node{
    int to,next;
};
void solve(){
    int n,cnt=0;
    cin>>n;
    vector<node> edge(2*n+1);
    vector<int> head(n+1);
    vector<fraction> a(n+1);
    auto add_edge=[&](int u,int v){
        edge[++cnt].to=v;
        edge[cnt].next=head[u];
        head[u]=cnt;
    };
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        add_edge(u,v);
        add_edge(v,u);
    }
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        a[i]=fraction(15,x);
    }
    fraction ans=fraction(0,1);
    function<void(int,int,fraction)> dfs=[&](int u,int fa,fraction res){
        if(ans<res) ans=res;
        for(int i=head[u];i;i=edge[i].next){
            int v=edge[i].to;
            if(v==fa) continue;
            dfs(v,u,res+a[v]);
        }
    };
    dfs(1,0,a[1]);
    ans.print();
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}