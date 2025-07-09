#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int T,n;
int f[3][maxn][2],a[3][maxn];
struct node{
    int x,y,step;
    node(int _row,int _col,int _step){
        x=_row;
        y=_col;
        step=_step;
    }
};
int n_x[4]={0,0,1,-1},n_y[4]={1,-1,0,0};
queue<node> q;
void bfs()
{
    f[1][1][1]=1;
    q.push(node(1,1,1));
    while(q.size()){
        node u=q.front();
        q.pop();
        if(u.step==1){
            for(int i=0;i<=3;i++){
                int nx=u.x+n_x[i],ny=u.y+n_y[i];
                if(nx>=1&&nx<=2&&ny>=1&&ny<=n&&f[nx][ny][0]==-1){
                    f[nx][ny][0]=1;
                    q.push(node(nx,ny,0));
                }
            }
        }else{
            if(u.y+1<=n&&a[u.x][u.y]==2){
                if(f[u.x][u.y+1][1]==-1){
                    f[u.x][u.y+1][1]=1;
                    q.push(node(u.x,u.y+1,1));
                }
            }else{
                if(u.y-1&&f[u.x][u.y-1][0]==-1){
                    f[u.x][u.y-1][0]=1;
                    q.push(node(u.x,u.y-1,1));
                }
            }
        }
    }
}
int main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int j=1;j<=2;j++){
            for(int i=1;i<=n;i++){
                char ch=getchar();
                while(ch!='<'&&ch!='>')
                    ch=getchar();
                if(ch=='<')
                    a[j][i]=1;
                else
                    a[j][i]=2;
            }
        }
        for(int i=1;i<=2;i++)
            for(int j=1;j<=n;j++)
                f[i][j][0]=f[i][j][1]=-1;
        bfs();
        if(f[2][n][1]==1)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}