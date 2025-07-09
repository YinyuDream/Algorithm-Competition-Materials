#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,m;
int a[maxn],b[maxn],c[maxn];
int f(int i,int x)
{
    return a[i]*x*x+b[i]*x+c[i];
}
struct node{
    int id,var_x;
    node(int _id,int _var_x){
        id=_id;
        var_x=_var_x;
    }
    friend bool operator <(node x,node y){
        return f(x.id,x.var_x)>f(y.id,y.var_x);
    }
};
priority_queue<node> q;
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>b[i]>>c[i];
    for(int i=1;i<=n;i++)
        q.push(node(i,1));
    for(int i=1;i<=m;i++){
        node p=q.top();
        q.pop();
        cout<<f(p.id,p.var_x)<<" ";
        q.push(node(p.id,p.var_x+1));
    }
    return 0;
}