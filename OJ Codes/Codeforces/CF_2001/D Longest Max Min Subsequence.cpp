#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void write(int x)
{
    if(x<0) putchar('-'),x=-x;
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
void solve(){
    int n=read();
    set<int>lim;
    multiset<int>st;
    vector<int> a(n),mx(n+1),bk(n+1),pos[n+1];
    for(int i=0;i<n;i++){
        a[i]=read();
        bk[a[i]]=1;
        mx[a[i]]=max(mx[a[i]],i);
        pos[a[i]].push_back(i);
    }
    for(int i=0;i<n;i++)
        lim.insert(mx[a[i]]);
    int now=0,val=lim.size();
    for(int i=now;i<=min(*lim.begin(),n-1);i++)
        st.insert(a[i]);
    vector<int> ans;
    for(int i=1;i<=val;i++){
        if(now==*lim.begin()){
            ans.push_back(a[now]);
            bk[a[now]]=0;
            lim.erase(mx[a[now]]);
            st.erase(a[now]);
            now++;
            for(int j=now;j<=min(*lim.begin(),n-1);j++)
                if(bk[a[j]])
                    st.insert(a[j]);
            continue;
        }
        int mxval=i%2==1?*st.rbegin():*st.begin();
        int mxpos=*lower_bound(pos[mxval].begin(),pos[mxval].end(),now);
        ans.push_back(a[mxpos]);
        bk[a[mxpos]]=0;
        st.erase(a[mxpos]);
        for(int j=now;j<mxpos;j++)
            if(bk[a[j]])
                st.erase(st.find(a[j]));
        now=mxpos+1;
        int olim=*lim.begin();
        lim.erase(mx[a[mxpos]]);
        for(int j=olim+1;j<=min(*lim.begin(),n-1);j++)
            if(bk[a[j]])
                st.insert(a[j]);
    }
    write(ans.size());
    putchar('\n');
    for(int i=0;i<ans.size();i++){
        write(ans[i]);
        putchar(' ');
    }
    putchar('\n');
}
int main(){
    int T=read();
    while(T--){
        solve();
    }
    return 0;
}