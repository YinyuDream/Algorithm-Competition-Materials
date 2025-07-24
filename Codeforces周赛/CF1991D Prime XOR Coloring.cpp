#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
vector<int> prime;
int isprime[maxn],lim[maxn];
void init(){
    memset(isprime,true,sizeof(isprime));
    isprime[0]=isprime[1]=false;
    for(int i=2;i<maxn;i++){
        if(isprime[i]){
            prime.push_back(i);
            for(int j=i+i;j<maxn;j+=i){
                isprime[j]=false;
            }
        }
    }
    for(int i=1;i<maxn;i++){
        int val=i;
        while(val){
            lim[i]++;
            val>>=1;
        }
        lim[i]=(1<<lim[i])-1;
    }
    int cnt=0;
    vector<int> G[110];
    for(int i=1;i<=8;i++)
        for(int j=i+1;j<=8;j++)
            if(isprime[i^j])
                cout<<i<<" "<<j<<endl;
            
    int x=26;
    for(auto i:G[x])
        if(i<x)
            cout<<i<<" ";
    cout<<endl;
    x++;
    for(auto i:G[x])
        if(i<x)
            cout<<i<<" ";
    cout<<endl;
    cout<<cnt<<endl;
}
void solve(){
    int n;
    cin>>n;
    vector<int> col(n+1);
    set<int> st;
    col[1]=1;
    st.insert(1);
    int mx=prime.size();
    for(int i=2;i<=n;i++){
        int mex=1;
        unordered_set<int> s;
        for(int j=0;j<mx;j++){
            if(prime[j]>lim[i]){
                break;
            }
            if((i^prime[j])<i){
                s.insert(col[i^prime[j]]);
            }
            while(s.count(mex)){
                mex++;
            }
        }
        col[i]=mex;
        st.insert(col[i]);
    }
    cout<<st.size()<<endl;
    for(int i=1;i<=n;i+=4){
        cout<<col[i]<<" "<<col[i+1]<<" "<<col[i+2]<<" "<<col[i+3]<<endl;
    }
    cout<<endl;
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