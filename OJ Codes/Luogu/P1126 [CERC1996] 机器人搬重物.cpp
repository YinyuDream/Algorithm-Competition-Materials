#include<cstdio>
#include<queue>
#include<cstring>
#include<cstdlib>
using namespace std;
const int maxn=1e3+10;
int n,m,t,stx,sty,edx,edy,ans=0x7f7f7f7f;
char c;
int mapp[maxn][maxn];
int f[maxn][maxn][4],book[maxn][maxn][4];
struct node{
	int x,y,pos,step;
	node(int _x,int _y,int _pos,int _step){
		x=_x,y=_y,pos=_pos,step=_step;
	}
};
queue<node>q;
int main(){
	memset(f,-1,sizeof f);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&mapp[i][j]),
			mapp[i][j]=!mapp[i][j];
	scanf("%d%d%d%d %c",&stx,&sty,&edx,&edy,&c);
	if(!mapp[stx][sty]||!mapp[stx][sty+1]||!mapp[stx+1][sty]||!mapp[stx+1][sty+1])puts("-1"),exit(0);
	if(stx==edx&&sty==edy)puts("0"),exit(0);
	if(c=='E')t=0;
	else if(c=='S')t=1;
	else if(c=='W')t=2;
	else t=3;
	q.push(node(stx,sty,t,0));
	book[stx][sty][t]=1;
	while(q.size())
	{
		node t=q.front();q.pop();
		if(!book[t.x][t.y][(t.pos+1)%4])
		q.push(node(t.x,t.y,(t.pos+1)%4,t.step+1)),book[t.x][t.y][(t.pos+1)%4]=1,f[t.x][t.y][(t.pos+1)%4]=t.step+1;
		if(!book[t.x][t.y][(t.pos+3)%4])
		q.push(node(t.x,t.y,(t.pos+3)%4,t.step+1)),book[t.x][t.y][(t.pos+3)%4]=1,f[t.x][t.y][(t.pos+3)%4]=t.step+1;
		for(int i=1;i<=3;i++)
		{
			if(t.pos==0){
				if(mapp[t.x][t.y+i]&&mapp[t.x+1][t.y+i]&&mapp[t.x][t.y+i+1]&&mapp[t.x+1][t.y+i+1]&&book[t.x][t.y+i][t.pos]==0)
				book[t.x][t.y+i][t.pos]=1,q.push(node(t.x,t.y+i,t.pos,t.step+1)),f[t.x][t.y+i][t.pos]=t.step+1;
				else break;
			}else if(t.pos==1){
				if(mapp[t.x+i][t.y]&&mapp[t.x+i+1][t.y]&&mapp[t.x+i][t.y+1]&&mapp[t.x+i+1][t.y+1]&&book[t.x+i][t.y][t.pos]==0)
				book[t.x+i][t.y][t.pos]=1,q.push(node(t.x+i,t.y,t.pos,t.step+1)),f[t.x+i][t.y][t.pos]=t.step+1;
				else break;
			}else if(t.pos==2){
				if(mapp[t.x][t.y-i]&&mapp[t.x+1][t.y-i]&&mapp[t.x][t.y+1-i]&&mapp[t.x+1][t.y+1-i]&&book[t.x][t.y-i][t.pos]==0)
				book[t.x][t.y-i][t.pos]=1,q.push(node(t.x,t.y-i,t.pos,t.step+1)),f[t.x][t.y-i][t.pos]=t.step+1; 		
				else break;
			}else{
				if(mapp[t.x-i][t.y]&& mapp[t.x-i+1][t.y]&&mapp[t.x-i][t.y+1]&&mapp[t.x-i+1][t.y+1]&&book[t.x-i][t.y][t.pos]==0)
				book[t.x-i][t.y][t.pos]=1,q.push(node(t.x-i,t.y,t.pos,t.step+1)),f[t.x-i][t.y][t.pos]=t.step+1;	
				else break;
			}
		}
	}
	for(int i=0;i<=3;i++)
		ans=min(ans,f[edx][edy][i]);
	if(ans!=0x7f7f7f7f)printf("%d",ans);
	else puts("-1");	
	return 0;
}
