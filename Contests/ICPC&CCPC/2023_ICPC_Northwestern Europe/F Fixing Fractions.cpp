#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
    ll val;
    int pos;
    node(ll _val=0,int _pos=0):val(_val),pos(_pos){}
};
bool operator<(const node &a,const node &b){
    if(a.val!=b.val)
        return a.val<b.val;
    return a.pos<b.pos;
}
vector<node> num_a,num_b;
int len(ll x){
    int res=0;
    while(x){
        res++;
        x/=10;
    }
    return res;
}
node work(ll x,int pos)
{
    int len_x=len(x),mx=0;
    ll res=0;
    for(int i=0;i<len_x;i++){
        if((pos>>i)&1)
            res=res*10+x%10,mx++;
        x/=10;
    }
    for(int i=1;i<=mx;i++){
        x=x*10+res%10;
        res/=10;
    }
    return node(x,mx);
}
bool check(node x,ll a,node y,ll b){
    vector<int> num_x,num_a,num_y,num_b;
    for(int i=0;i<x.pos;i++){
        num_x.push_back(x.val%10);
        x.val/=10;
    }
    while(a){
        num_a.push_back(a%10);
        a/=10;
    }
    for(int i=0;i<y.pos;i++){
        num_y.push_back(y.val%10);
        y.val/=10;
    }
    while(b){
        num_b.push_back(b%10);
        b/=10;
    }
    reverse(num_x.begin(),num_x.end());
    reverse(num_a.begin(),num_a.end());
    reverse(num_y.begin(),num_y.end());
    reverse(num_b.begin(),num_b.end());
    multiset<int> dif_x,dif_y;
    int now_x=0,now_y=0;
    for(int i=0;i<num_a.size();i++){
        if(now_x<num_x.size()&&num_x[now_x]==num_a[i]){
            now_x++;
        }else{
            dif_x.insert(num_a[i]);
        }
    }
    for(int i=0;i<num_b.size();i++){
        if(now_y<num_y.size()&&num_y[now_y]==num_b[i]){
            now_y++;
        }else{
            dif_y.insert(num_b[i]);
        }
    }
    if(now_x<num_x.size()||now_y<num_y.size())
        return false;
    if(dif_x!=dif_y)
        return false;
    return true;
}
void solve(){
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    int len_a=len(a),len_b=len(b);
    for(int i=0;i<(1<<len_a);i++){
        num_a.push_back(work(a,i));
    }
    for(int i=0;i<(1<<len_b);i++){
        num_b.push_back(work(b,i));
    }
    sort(num_a.begin(),num_a.end());
    sort(num_b.begin(),num_b.end());
    auto it=num_b.begin();
    for(auto x:num_a){
        if(x.val==0)continue;
        __int128_t _x=x.val,_d=d,_c=c;
        if(_x*_d%_c!=0||_x*_d/_c>1e18){
            continue;
        }
        ll y=_x*_d/_c;
        while(it!=num_b.end()&&it->val<y){
            it++;
        }
        for(;it!=num_b.end();it++){
            node tmp=*it;
            if(tmp.val!=y)break;
            if(check(x,a,tmp,b)){
                cout<<"possible"<<endl;
                cout<<x.val<<' '<<tmp.val<<endl;
                return;
            }
        }
    }
    cout<<"impossible"<<endl;
}
int main(){
    solve();
    return 0;
}