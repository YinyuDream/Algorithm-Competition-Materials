#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int T,n,a[maxn];
long long suma[maxn],sumb[maxn],sumc[maxn];
set<long long> st;
int main(){
    cin>>T;
    while(T--){
        bool flag=0;
        st.clear();
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i],suma[i]=sumb[i]=sumc[i]=0;
        for(int i=1;i<=n;i++)
            if(i%2==0)suma[i]+=a[i];
            else sumb[i]+=a[i];
        for(int i=1;i<=n;i++){
            suma[i]+=suma[i-1];
            sumb[i]+=sumb[i-1];
        }
        for(int i=1;i<=n;i++)
            sumc[i]=suma[i]-sumb[i];
        st.insert(0);
        for(int i=1;i<=n;i++){
            if(st.find(sumc[i])!=st.end()){
                puts("YES");
                flag=1;
                break;
            }else{
                st.insert(sumc[i]);
            }
        }
        if(!flag)puts("NO");
    }
    return 0;
}