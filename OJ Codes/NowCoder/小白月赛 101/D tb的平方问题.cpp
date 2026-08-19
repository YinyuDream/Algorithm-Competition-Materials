#include<bits/stdc++.h>
using namespace std;
constexpr int lim=1e4;
int main(){
    set<int> st;
    for(int i=1;i<=lim;i++){
        st.insert(i*i);
    }
    int n,q;
    cin>>n>>q;
    vector<int> a(n+1),sum(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    vector<pair<int,int>> interval;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            int d=sum[j]-sum[i-1];
            if(st.count(d)){
                interval.push_back({i,j});
            }
        }
    }
    vector<pair<int,int>> interval_2=interval;
    sort(interval.begin(),interval.end(),[&](pair<int,int> a,pair<int,int> b){
        if(a.first==b.first){
            return a.second<b.second;
        }
        return a.first<b.first;
    });
    sort(interval_2.begin(),interval_2.end(),[&](pair<int,int> a,pair<int,int> b){
        if(a.second==b.second){
            return a.first<b.first;
        }
        return a.second<b.second;
    });
    for(int i=1;i<=q;i++){
        int x;
        cin>>x;
        int ans=interval.size();
        int pos=lower_bound(interval.begin(),interval.end(),make_pair(x+1,0),[&](pair<int,int> a,pair<int,int> b){
            if(a.first==b.first){
                return a.second<b.second;
            }
            return a.first<b.first;
        })-interval.begin();
        ans-=interval.size()-pos;
        pos=lower_bound(interval_2.begin(),interval_2.end(),make_pair(0,x),[&](pair<int,int> a,pair<int,int> b){
            if(a.second==b.second){
                return a.first<b.first;
            }
            return a.second<b.second;
        }
        )-interval_2.begin()-1;
        ans-=pos+1;
        cout<<ans<<endl;
    }
    return 0;
}