#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void solve(){
    int n,L,D;
    n=read();L=read();D=read();
    vector<int> a(n),b;
    for(int i=0;i<n;i++){
        a[i]=read();
    }
    int res=a[0];
    a.erase(a.begin());
    b.push_back(res);
    sort(a.begin(),a.end());
    if(res<L){
        b.push_back(a.back());
        a.pop_back();
        b.push_back(a.front());
        a.erase(a.begin());
        b.push_back(a.front());
        a.erase(a.begin());
    }else{
        b.push_back(a.front());
        a.erase(a.begin());
        b.push_back(a.front());
        a.erase(a.begin());
        b.push_back(a.front());
        a.erase(a.begin());
    }
    sort(b.begin(),b.end());
    int cnt=0;
    for(auto x:b)
        cnt+=(x>=L);
    if(cnt<=1&&b[3]-b[0]>D){
        puts("Yes");
    }else{
        puts("No");
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