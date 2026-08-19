#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n;
struct node{
    int a,b;
}p[maxn];
int mx[maxn];
priority_queue<int> q_up;
priority_queue<int,vector<int>,greater<int>> q_down;
int main(){
    cin>>T;
    while(T--){
        while(q_up.size())q_up.pop();
        while(q_down.size())q_down.pop();
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>p[i].a>>p[i].b;
        sort(p+1,p+n+1,[](node a,node b){
            return a.a<b.a;
        });
        mx[n+1]=0;
        for(int i=n;i;i--)
            mx[i]=max(mx[i+1],p[i].b);
        int ans=abs(p[1].a-mx[2]);
        for(int i=2;i<=n;i++){
            q_up.push(p[i-1].b);
            while(q_up.size()&&q_up.top()>p[i].a){
                q_down.push(q_up.top());
                q_up.pop();
            }
            while(q_down.size()&&q_down.top()<=p[i].a){
                q_up.push(q_down.top());
                q_down.pop();
            }
            if(i==n)break;
            if(q_up.size()){
                int num_up=max(mx[i+1],q_up.top());
                ans=min(ans,abs(p[i].a-num_up));
            }
            if(q_down.size()){
                int num_down=max(mx[i+1],q_down.top());
                ans=min(ans,abs(p[i].a-num_down));
            }
            ans=min(ans,abs(p[i].a-mx[i+1]));
        }
        if(q_up.size())
            ans=min(ans,abs(p[n].a-q_up.top()));
        if(q_down.size())
            ans=min(ans,abs(p[n].a-q_down.top()));
        cout<<ans<<endl;
    }
    return 0;
}