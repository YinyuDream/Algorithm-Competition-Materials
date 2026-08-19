#include<bits/stdc++.h>
using namespace std;
const int P=998244353;

int qpow(int x, int y) {
    int res=1;
    while(y){
        if(y&1)res=1ll*res*x%P;
        x=1ll*x*x%P;
        y>>=1;
    }
    return res;
}

void ntt(vector<int> &x,vector<int> &r, int lim, int opt) {
    for(int i=0;i<lim;++i)
        if(r[i]<i)
            swap(x[i],x[r[i]]);
    for(int m=2;m<=lim;m<<=1){
        int k=m>>1;
        int gn=qpow(3,(P-1)/m);
        for(int i=0;i<lim;i+=m){
            int g=1;
            for(int j=0;j<k;++j,g=1ll*g*gn%P){
                int tmp=1ll*x[i+j+k]*g%P;
                x[i+j+k]=(x[i+j]-tmp+P)%P;
                x[i+j]=(x[i+j]+tmp)%P;
            }
        }
    }
    if(opt==-1){
        reverse(x.begin()+1,x.begin()+lim);
        int inv=qpow(lim,P-2);
        for(int i=0;i<lim;++i)
            x[i]=1ll*x[i]*inv%P;
    }
}
vector<int> calclate(vector<int> A, vector<int> B){
    int lim=1;
    int n=A.size();
    while(lim<(n<<1))lim<<=1;
    n=B.size();
    while(lim<(n<<1))lim<<=1;
    A.resize(lim,0);
    B.resize(lim,0);
    vector<int> r(lim);
    for(int i=0;i<lim;++i) 
        r[i]=(i&1)*(lim>>1)+(r[i>>1]>>1);
    ntt(A,r,lim,1);
    ntt(B,r,lim,1);
    vector<int> C(lim);
    for(int i=0;i<lim;++i)C[i]=1ll*A[i]*B[i]%P;
    ntt(C,r,lim,-1);
    return C;
}
vector<int> qpow(vector<int> &x, int y) {
    vector<int> res(x.size(),0);
    res[0]=1;
    while(y){
        if(y&1)res=calclate(res,x);
        x=calclate(x,x);
        y>>=1;
    }
    return res;
}
int main(){
    int m,k,T;
    cin>>m>>k>>T;
    vector<int> A(m+1,1);
    vector<int> ans=qpow(A,k);
    cout<<ans[T]<<endl;
    return 0;
}