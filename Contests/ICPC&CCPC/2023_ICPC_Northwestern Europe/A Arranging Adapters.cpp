#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,s,ans;
int a[maxn],book[maxn];
multiset<int> st;
int main(){
    cin>>n>>s;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        st.insert(a[i]);
    }
    sort(a+1,a+n+1);
    if(n==1||s==1){
        cout<<1<<endl;
        return 0;
    }
    s--,ans++,book[n]=1,st.erase(st.find(a[n]));
    int x=0,y=0;
    while(true){
        for(auto i=st.begin();i!=st.end();){
            int len=(*i-1)/3+1;
            if(s-len>=0){
                ans++;
                s-=len;
                if(*i%3==1)
                    x++;
                if(*i%3==2)
                    y++;
                i=st.erase(i);
            }else{
                break;
            }
        }
        int now=s;
        while(x&&y)
            x--,y--,s++;
        while(x>=2)
            x-=2,s++;
        if(now==s)
            break;
    }
    if(s&&st.size())
        ans++;
    cout<<ans<<endl;
    return 0;
}