#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxk=7;
const int maxlogn=60;
class matrix{
    private:
    const ll mod=998244353;
    ll a[1<<(maxk+1)][1<<(maxk+1)];
    int n,m;
    public:
    matrix(){};
    void init(int x,int y){
        n=x;
        m=y;
    }
    matrix operator*(const matrix &b){
        matrix c;
        c.init(n,b.m);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                for(int k=1;k<=b.m;k++){
                    c.a[i][k]=(c.a[i][k]+a[i][j]*b.a[j][k]%mod)%mod;
                }
            }
        }
        return c;
    }
    matrix operator=(const matrix &b){
        n=b.n;
        m=b.m;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                a[i][j]=b.a[i][j];
            }
        }
        return *this;
    }
    matrix operator^(int x){
        matrix c;
        c.init(n,m);
        matrix b=*this;
        for(int i=1;i<=n;i++){
            c.a[i][i]=1;
        }
        while(x){
            if(x&1){
                c=c*b;
            }
            b=b*b;
            x>>=1;
        }
        return c;
    }
    void value(int i,int j,ll x){
        a[i][j]=x;
    }
    ll value(int i,int j){
        return a[i][j];
    }
};
matrix A[maxk+1];
matrix x[maxk+1][maxlogn+1];
void init(){
    for(int i=0;i<=maxk;i++){
        int k=i;
        matrix x1;
        x1.init((1<<(k+1))-1,(1<<(k+1))-1);
        for(int j=0;j<(1<<(k+1));j++){
            if(j&1){
                int val=j>>1;
                if(val&1){
                    x1.value(j,val,1);
                }else{
                    for(int l=0;l<=k;l++){
                        if(!((val>>l)&1)){
                            x1.value(j,val|(1<<l)|1,1);
                        }
                    }
                }
            }
        }
        x[k][0]=x1;
        for(int j=1;j<=maxlogn;j++){
            cout<<i<<" "<<j<<endl;
            x[k][j]=x[k][j-1]*x[k][j-1];
        }
    }
    for(int i=0;i<=maxk;i++){
        int k=i;
        A[k].init(1,(1<<(k+1))-1);
        for(int j=0;j<=k;j++){
            A[k].value(1,(1<<j)|1,1);
        }
    }
}
void solve(){
    int n,k;
    cin>>n>>k;
    matrix y;
    y.init((1<<(k+1))-1,(1<<(k+1))-1);
    for(int i=0;i<=maxlogn;i++){
        if(((n-1)>>i)&1){
            y=y*x[k][i];
        }
    }
    y=A[k]*y;
    cout<<y.value(1,1)<<endl;
}
int main(){
    init();
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}