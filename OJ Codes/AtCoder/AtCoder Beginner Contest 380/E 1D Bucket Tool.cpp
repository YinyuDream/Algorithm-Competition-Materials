#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,q;
    cin>>n>>q;
    set<tuple<int,int,int>> s;
    vector<int> cnt(n+1,1);
    for(int i=1;i<=n;i++){
        s.insert({i,i,i});
    }
    while(q--){
        int op;
        cin>>op;
        if(op==1){
            int x,c;
            cin>>x>>c;
            auto it=prev(s.upper_bound({x,n+1,0}));
            auto seg=*it;
            s.erase(it);
            cnt[get<2>(seg)]-=get<1>(seg)-get<0>(seg)+1;
            get<2>(seg)=c;
            s.insert(seg);
            cnt[c]+=get<1>(seg)-get<0>(seg)+1;
            it=prev(s.upper_bound({x,n+1,0}));
            if(it!=s.begin()){
                auto pre=prev(it);
                if(get<2>(*pre)==c){
                    int l1=get<0>(*pre),r1=get<1>(*it);
                    s.erase(pre);
                    s.erase(it);
                    s.insert({l1,r1,c});
                }
            }
            it=prev(s.upper_bound({x,n+1,0}));
            if(next(it)!=s.end()){
                auto nxt=next(it);
                if(get<2>(*nxt)==c){
                    int l1=get<0>(*it),r1=get<1>(*nxt);
                    s.erase(it);
                    s.erase(nxt);
                    s.insert({l1,r1,c});
                }
            }
        }else{
            int c;
            cin>>c;
            cout<<cnt[c]<<endl;
        }
    }
    return 0;
}