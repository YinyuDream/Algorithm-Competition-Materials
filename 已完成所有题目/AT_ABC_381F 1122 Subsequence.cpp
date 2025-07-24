#include<bits/stdc++.h>
using namespace std;
struct node{
    int eth,state,val,dis;
};
int main(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    vector<vector<int>> nxt(n+1,vector<int>(21,-1));
    for(int i=1;i<=n;i++){
         a[i]=rand()%20+1;
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
    vector<int> book(21,0);
    for(int i=1;i<=n;i++){
        if(book[a[i]]) continue;
        book[a[i]]=1;
        q.push({i,1<<a[i],a[i],1});
    }
    int cnt=0;
    while(q.size()){
        cnt++;
        auto [eth,state,val,dis]=q.front();
        q.pop();
        if(dis%2==0){
            ans=max(ans,dis);
        }
        if(dis&1){
            int nxtpos=nxt[eth][val];
            if(nxtpos!=-1){
                q.push({nxtpos,state,val,dis+1});
            }
        }else{
            for(int i=1;i<=20;i++){
                if(!(state&(1<<i))){
                    int nxtpos=nxt[eth][i];
                    if(nxtpos!=-1){
                        q.push({nxtpos,state|(1<<i),i,dis+1});
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
    cout<<cnt<<endl;
    return 0;
}