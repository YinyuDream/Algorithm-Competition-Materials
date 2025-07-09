#include<bits/stdc++.h>
using namespace std;
const int maxn=110;
int x,y,p,q,ans=0x7f7f7f7f;
int f[maxn][maxn][2],book[maxn][maxn][2];//0：在左边，1：在右边
struct node{
    int x,y,t;
    node(int _x,int _y,int _t){
        x=_x,y=_y,t=_t;
    }
};
queue<node>Q;
void bfs()
{
    memset(f,0x7f,sizeof f);
    f[0][0][0]=0;
    book[0][0][0]=1;
    Q.push(node(0,0,0));
    while(Q.size()){
        node u=Q.front();
        Q.pop();
        int rx=u.x,ry=u.y;//if(rx==0&&ry==2)puts("dw");
        int lx=x-rx,ly=y-ry;
        if(u.t==0){//l->r
            for(int i=0;i<=lx;i++){
                for(int j=0;j<=ly&&i+j<=p;j++){
                    if((ly-j<=lx-i+q||lx==i)&&(!book[i+rx][j+ry][1])){
                        Q.push(node(i+rx,j+ry,1));
                        f[i+rx][j+ry][1]=f[rx][ry][0]+1;
                        book[i+rx][j+ry][1]=1;
                    }
                }
            }
        }else{
            
            for(int i=0;i<=rx;i++){
                for(int j=0;j<=ry&&i+j<=p;j++){
                    if((ry-j<=rx-i+q||rx==i)&&(!book[rx-i][ry-j][0])){
                        Q.push(node(rx-i,ry-j,0));
                        f[rx-i][ry-j][0]=f[rx][ry][1]+1;
                        book[rx-i][ry-j][0]=1;
                    }
                }
            }
        }
    }
}
int main(){
    cin>>x>>y>>p>>q;
    bfs();
    for(int i=0;i<=y;i++)
        ans=min(ans,f[x][i][1]);
    cout<<(ans>1e9?-1:ans);
    //for(int i=0;i<=x;i++)
    //    for(int j=0;j<=y;j++)
    //        cout<<"羊"<<i<<" "<<"狼"<<j<<" "<<(f[i][j][0]==0x7f7f7f7f?-1:f[i][j][0])<<" "<<(f[i][j][1]==0x7f7f7f7f?-1:f[i][j][1])<<endl;
    return 0;
}