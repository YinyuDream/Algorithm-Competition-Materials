#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll p=998244353,inv4=748683265;
int read()
{
    int x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x;
}
struct matrix{
    vector<vector<ll>> a;
    matrix(int n,int m){
        a.resize(n,vector<ll>(m,0));
    }
    matrix operator*(const matrix &b){
        matrix c(a.size(),b.a[0].size());
        for(int i=0;i<a.size();i++){
            for(int j=0;j<b.a[0].size();j++){
                for(int k=0;k<b.a.size();k++){
                    c.a[i][j]=(c.a[i][j]+a[i][k]*b.a[k][j])%p;
                }
            }
        }
        return c;
    }
};
ll work()
{
	bool flag=0;
    ll x=0;
	char ch=getchar();
    while(ch<'0'||ch>'9'){
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        if(x>=p-1){
            flag=1;
            x%=p-1;
        }
        ch=getchar();
    }
    if(flag)x+=p-1;
    return x;
}
matrix fast_pow(matrix x,ll y)
{
    matrix c(x.a.size(),x.a.size());
    for(int i=0;i<x.a.size();i++){
        c.a[i][i]=1;
    }
    while(y){
        if(y&1)c=c*x;
        x=x*x;
        y>>=1;
    }
    return c;
}
void solve()
{
    ll val_1=work();
    matrix op(4,4);
    op.a[1][0]=1,op.a[2][1]=1,op.a[3][2]=1;
    op.a[0][3]=op.a[1][3]=op.a[2][3]=op.a[3][3]=inv4;
    op=fast_pow(op,val_1);
    matrix x(1,4);
    x.a[0][3]=1;
    x=x*op;
    cout<<x.a[0][3]<<endl;
}
int main(){
	int T;
    T=read();
    while(T--){
        solve();
    }
	return 0;
}