#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n;
int a[maxn],d[maxn],l[maxn],r[maxn],book[maxn];
vector<int>v;
set<int>st;
int main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++) book[i]=0;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++) cin>>d[i];
        for(int i=1;i<=n;i++) l[i]=i-1,r[i]=i+1;
        r[0]=1,l[n+1]=n,l[0]=r[n+1]=0;
        a[0]=a[n+1]=d[0]=d[n+1]=0;
        for(int i=1;i<=n;i++)
            if(d[i]<a[i-1]+a[i+1])
                v.push_back(i);
        for(int j=1;j<=n;j++){
            int cnt=0;
            for(auto i:v){
                book[i]=1;
                if(l[i]>=1)st.insert(l[i]);
                if(r[i]<=n)st.insert(r[i]);
                r[l[i]]=r[i];
                l[r[i]]=l[i];
                cnt++;
            }
            v.clear();
            for(auto i:st){
                if(!book[i]&&d[i]<a[l[i]]+a[r[i]]){
                    v.push_back(i);
                }
            }
            st.clear();
            cout<<cnt<<" ";
        }
        cout<<endl;
    }
    return 0;
}