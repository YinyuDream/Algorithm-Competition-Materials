#include<bits/stdc++.h>
using namespace std;
const int N=50;
int n,m,cnt_block,Hm,Hr,Hc,Hx,Hy;
int freeze[N][N];
bool block[N][N][N],book[N][N][N];
int dx[]={-1,-1,0,1,1,1,0,-1},dy[]={0,-1,-1,-1,0,1,1,1};
int _dx[]={1,-1,0,0,0,0},_dy[]={0,0,1,-1,0,0},_dz[]={0,0,0,0,1,-1};
struct point{
	int x,y,z;
	point(){}
	point(int _x,int _y,int _z){
		x=_x,y=_y,z=_z;
	}
};
void ice_barrage(int x,int y,int d,int s)
{
	int cnt=0;
	while(!block[x][y][0]&&x<n&&y<n&&x>=0&&y>=0&&s--){
		if(freeze[x][y]<4){
			freeze[x][y]++;
			cnt++;
		}
		x=x+dx[d];
		y=y+dy[d];
	}
	printf("CIRNO FREEZED %d BLOCK(S)\n",cnt);
}
void make_ice_block()
{
	int cnt=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(freeze[i][j]==4)
				cnt++,freeze[i][j]=0;
	cnt_block+=cnt;
	printf("CIRNO MADE %d ICE BLOCK(S),NOW SHE HAS %d ICE BLOCK(S)\n",cnt,cnt_block);
}
bool check(int x,int y,int z)
{
	bool flag=0;
	for(int i=0;i<=5;i++)
		flag|=block[x+_dx[i]][y+_dy[i]][z+_dz[i]];
	return flag;
}
void put_ice_block(int x,int y,int z)
{
	if(!cnt_block)
		puts("CIRNO HAS NO ICE_BLOCK");
	else if(block[x][y][z]||(!check(x,y,z)&&z))
		puts("BAKA CIRNO,CAN'T PUT HERE");
	else if(x<Hr||x>Hr+Hx-1||y<Hc||y>Hc+Hy-1){
		puts("CIRNO MISSED THE PLACE");
		block[x][y][z]=true;
		cnt_block--;
	}
	else if(Hr+1<=x&&x<=Hr+Hx-2&&Hc+1<=y&&y<=Hc+Hy-2){
		puts("CIRNO PUT AN ICE_BLOCK INSIDE THE HOUSE");
		block[x][y][z]=true;
		cnt_block--;
	}
	else{
		block[x][y][z]=true;
		printf("CIRNO SUCCESSFULLY PUT AN ICE_BLOCK,NOW SHE HAS %d ICE_BLOCK(S)\n",--cnt_block);
		if(!z)freeze[x][y]=0;
	} 
}
bool bfs(int x,int y,int z)
{
	bool flag=0;
	queue<point>q;
	memset(book,0,sizeof book);
	q.push(point(x,y,z));
	book[x][y][z]=true;
	while(!q.empty()){
		x=q.front().x,y=q.front().y,z=q.front().z;
		flag|=!z;
		q.pop();
		for(int i=0;i<=5;i++){
			int nx=x+_dx[i],ny=y+_dy[i],nz=z+_dz[i];
			if(nx<0||ny<0||nz<0||nx>=n||ny>=n||nz>=Hm||book[nx][ny][nz]||!block[nx][ny][nz])continue;
			book[nx][ny][nz]=true;
			q.push(point(nx,ny,nz));
		}
	}
	return flag;
}
int remove(int x,int y,int z)
{
	int cnt=0;
	queue<point>q;
	memset(book,0,sizeof book);
	q.push(point(x,y,z));
	book[x][y][z]=true;
	while(!q.empty()){
		x=q.front().x,y=q.front().y,z=q.front().z;
		cnt++;
		block[x][y][z]=false;
		q.pop();
		for(int i=0;i<=5;i++){
			int nx=x+_dx[i],ny=y+_dy[i],nz=z+_dz[i];
			if(nx<0||ny<0||nz<0||nx>=n||ny>=n||nz>=Hm||book[nx][ny][nz]||!block[nx][ny][nz])continue;
			book[nx][ny][nz]=true;
			q.push(point(nx,ny,nz));
		}
	}
	return cnt;
}
void remove_ice_block(int x,int y,int z)
{
	int cnt=0;
	if(!block[x][y][z]){
		puts("BAKA CIRNO,THERE IS NO ICE_BLOCK");
		return ;
	}
	block[x][y][z]=false;
	for(int i=0;i<=5;i++)
		if(!bfs(x+_dx[i],y+_dy[i],z+_dz[i])&&block[x+_dx[i]][y+_dy[i]][z+_dz[i]])
			cnt+=remove(x+_dx[i],y+_dy[i],z+_dz[i]);
	cnt?printf("CIRNO REMOVED AN ICE_BLOCK,AND %d BLOCK(S) ARE BROKEN\n",cnt):puts("CIRNO REMOVED AN ICE_BLOCK");
	cnt_block++;
}
int main(){
	scanf("%d%d%d%d%d%d%d",&n,&Hm,&Hr,&Hc,&Hx,&Hy,&m);
	for(int i=1,R,C,H,D,S;i<=m;i++){
		string opt;
		cin>>opt;
		if(opt=="ICE_BARRAGE"){
			scanf("%d%d%d%d",&R,&C,&D,&S);
			ice_barrage(R,C,D,S+1);
		}else if(opt=="MAKE_ICE_BLOCK"){
			make_ice_block();
		}else if(opt=="PUT_ICE_BLOCK"){
			scanf("%d%d%d",&R,&C,&H);
			put_ice_block(R,C,H);
		}else if(opt=="REMOVE_ICE_BLOCK"){
			cin>>R>>C>>H;
			remove_ice_block(R,C,H); 
		}else{
			
		}
	} 
	return 0;
}