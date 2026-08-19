#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,k;
int a[maxn],p[maxn];
deque<int> mn,mx;
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        p[a[i]]=i;
    }
    for(int i=1;i<=k;i++){
        while(mn.size()&&p[mn.back()]>p[i]) mn.pop_back();
        mn.push_back(i);
        while(mx.size()&&p[mx.back()]<p[i]) mx.pop_back();
        mx.push_back(i);
    }
    int ans=p[mx.front()]-p[mn.front()];
    for(int i=k+1;i<=n;i++){
        if(mn.front()<=i-k) mn.pop_front();
        if(mx.front()<=i-k) mx.pop_front();
        while(mn.size()&&p[mn.back()]>p[i]) mn.pop_back();
        mn.push_back(i);
        while(mx.size()&&p[mx.back()]<p[i]) mx.pop_back();
        mx.push_back(i);
        ans=min(ans,p[mx.front()]-p[mn.front()]);
    }
    cout<<ans<<endl;
    return 0;
}