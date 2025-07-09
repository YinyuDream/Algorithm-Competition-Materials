#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e3+10;
int T,n,m,x,ans;
int dir[maxn],dis[maxn],book[maxn][maxn];
queue<pair<int,int> >q;
int main(){
    cin>>T;
    while(T--){
        ans=0;
        cin>>n>>m>>x;
        for(int i=1;i<=m;i++){
            cin>>dis[i];
            char ch=getchar();
            while(ch!='0'&&ch!='1'&&ch!='?')
                ch=getchar();
            if(ch=='0')
                dir[i]=0;
            else if(ch=='1')
                dir[i]=1;
            else dir[i]=2;
        }
        while(q.size())
            q.pop();
        q.push(make_pair(x,0));
        for(int i=1;i<=n;i++)
            for(int j=0;j<=m;j++)
                book[i][j]=0;
        book[x][0]=1;
        for(int i=1;i<=m;i++){
            while(q.size()&&q.front().second==i-1){
                auto u=q.front();
                q.pop();
                if(dir[i]==0){
                    int nx=(u.first+dis[i])%n;
                    if(nx==0)
                        nx=n;
                    if(!book[nx][i]){
                        book[nx][i]=1;
                        q.push(make_pair(nx,i));
                    }
                }else if(dir[i]==1){
                    int nx=(u.first-dis[i])%n;
                    if(nx<=0)
                        nx+=n;
                    if(!book[nx][i]){
                        book[nx][i]=1;
                        q.push(make_pair(nx,i));
                    }
                }else{
                    int nx1=(u.first+dis[i])%n;
                    if(nx1==0)
                        nx1=n;
                    int nx2=(u.first-dis[i])%n;
                    if(nx2<=0)
                        nx2+=n;
                    if(!book[nx1][i]){
                        book[nx1][i]=1;
                        q.push(make_pair(nx1,i));
                    }
                    if(!book[nx2][i]){
                        book[nx2][i]=1;
                        q.push(make_pair(nx2,i));
                    }
                }
            }
        }
        for(int i=1;i<=n;i++)
            if(book[i][m])
                ans++;
        cout<<ans<<endl;
        for(int i=1;i<=n;i++)
            if(book[i][m])
                cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}