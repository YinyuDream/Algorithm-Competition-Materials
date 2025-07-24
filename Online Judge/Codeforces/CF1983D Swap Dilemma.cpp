#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}
void solve(){
    int n=read();
    vector<int> a(n+1),b(n+1);
    set<int> s1,s2;
    multiset<int> ms1,ms2;
    struct Binary_Indexed_Trees{
        vector<int> c;
        Binary_Indexed_Trees(int n):c(n+1,0){}
        int lowbit(int x){
            return x&(-x);
        }
        void update(int x,int v){
            int n=c.size();
            for(int i=x;i<n;i+=lowbit(i))
                c[i]+=v;
        }
        int query(int x){
            int res=0;
            for(int i=x;i;i-=lowbit(i))
                res+=c[i];
            return res;
        }
    };
    auto work=[&](vector<int> &a){
        Binary_Indexed_Trees bit(maxn);
        ll res=0;
        for(int i=1;i<=n;i++){
            res+=bit.query(maxn-1)-bit.query(a[i]);
            bit.update(a[i],1);
        }
        return res;
    };
    for(int i=1;i<=n;i++)
        a[i]=read(),s1.insert(a[i]),ms1.insert(a[i]);
    for(int i=1;i<=n;i++)
        b[i]=read(),s2.insert(b[i]),ms2.insert(b[i]);
    if(ms1!=ms2){
        cout<<"NO"<<endl;
        return;
    }
    int cnt_1=work(a),cnt_2=work(b);
    int can=(s1.size()!=n)||(s2.size()!=n);
    if(can){
        cout<<"YES"<<endl;
        return;
    }
    if(cnt_1%2==cnt_2%2){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
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