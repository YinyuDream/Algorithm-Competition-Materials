#include<bits/stdc++.h>
using namespace std;
struct node{
    int eth,state,val,cnt,dis;
};
int main(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    vector<vector<int>> nxt(n+1,vector<int>(21,-1));
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<int> last(21,-1);
    for(int i=n;i>=1;i--){
        for(int j=1;j<=20;j++){
            nxt[i][j]=last[j];
        }
        last[a[i]]=i;
    }
    int ans=0;
    queue<node> q;
    for(int i=1;i<=n;i++){
        q.push({i,1<<a[i],a[i],1,1});
    }
    while(q.size()){
        auto [eth,state,val,cnt,dis]=q.front();
        q.pop();
        if(cnt%2==0){
            ans=max(ans,dis);
        }
        if(cnt==1){
            int nxtpos=nxt[eth][val];
            if(nxtpos!=-1){
                q.push({nxtpos,state,val,cnt+1,dis+1});
            }
        }else{
            for(int i=1;i<=20;i++){
                if(i!=val){
                    int nxtpos=nxt[eth][i];
                    
                    if(nxtpos!=-1){
                        q.push({nxtpos,state|(1<<i),i,1,dis+1});
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}