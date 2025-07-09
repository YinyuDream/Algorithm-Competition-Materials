#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=1e6+10;
int pw10[6];
int dis[6][2][100001];
string to_string(int x,int len){
    string res;
    for(int i=0;i<len;i++){
        res+=x%10+'0';
        x/=10;
    }
    reverse(res.begin(),res.end());
    return res;
};
int to_int(string &s){
    int res=0;
    for(int i=0;i<s.size();i++)
        res=res*10+s[i]-'0';
    return res;
};
void init(int n){
    queue<pii>q;
    q.push({0,0});
    memset(dis,-1,sizeof(dis));
    dis[n][0][0]=0;
    while(q.size()){
        pii x=q.front();
        q.pop();
        for(int i=0;i<n;i++){
            string s=to_string(x.second,n),t=s;
            for(int j=i;j<n;j++){
                if(s[j]<'9')s[j]++;
                else s[j]='0';
                if(t[j]>'0')t[j]--;
                else t[j]='9';
                int vals=to_int(s),valt=to_int(t);
                int now_dis=dis[n][x.first][x.second];
                if(dis[n][(now_dis+1)%2][vals]==-1){
                    dis[n][(now_dis+1)%2][vals]=now_dis+1;
                    q.push({(now_dis+1)%2,vals});
                }
                if(dis[n][(now_dis+1)%2][valt]==-1){
                    dis[n][(now_dis+1)%2][valt]=now_dis+1;
                    q.push({(now_dis+1)%2,valt});
                }
            }
        }
    }
}
void solve(){
    int n,m;
    cin>>n>>m;
    init(n);
    auto check=[&](int x,int val,int step){
        string s=to_string(x,n);
        string t=to_string(val,n);
        for(int i=0;i<n;i++){
            if(t[i]>=s[i]){
                t[i]-=s[i];
            }else{
                t[i]=10-s[i]+t[i];
            }
        }
        for(int i=0;i<n;i++)
            t[i]+='0';
        int __val=to_int(t);
        return dis[n][step%2][__val]!=-1&&dis[n][step%2][__val]<=step;
    };
    vector<int>tot(pw10[n]);
    for(int i=0;i<m;i++){
        string s;
        int t;
        cin>>s>>t;
        int val=to_int(s);
        for(int j=0;j<pw10[n];j++){
            if(check(j,val,t)){
                tot[j]++;
            }
        }
    }
    int ans=-1,unique=1;
    for(int i=0;i<pw10[n];i++){
        if(tot[i]==m){
            if(ans==-1){
                ans=i;
            }else{
                unique=0;
                break;
            }
        }
    }
    if(ans!=-1&&unique){
        cout<<to_string(ans,n)<<endl;
    }else{
        if(ans==-1){
            cout<<"IMPOSSIBLE"<<endl;
        }else{
            cout<<"MANY"<<endl;
        }
    }
}
int main(){
    for(int i=1;i<6;i++)
        init(i);
    pw10[0]=1;
    for(int i=1;i<=5;i++)
        pw10[i]=pw10[i-1]*10;
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}