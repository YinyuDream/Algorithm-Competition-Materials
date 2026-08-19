#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node{
	int x,y;
}st,ed;
int dis(node a,node b)
{
	return abs(a.x-b.x)+abs(a.y-b.y);
}
int qibdis(node a,node b)
{
	return max(abs(a.x-b.x),abs(a.y-b.y));
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d%d%d%d%d",&n,&m,&st.x,&st.y,&ed.x,&ed.y);
	if(dis(st,ed)<=1)puts("-1");
	else if(ed.x<=2&&ed.y<=2&&ed.x>=n-1&&ed.y>=m-1)puts("1");
	else if(n<=2||m<=2){
		if(qibdis(st,ed)<=1)puts("3");
		else puts("2");
	}
	else if(max(ed.x-1,ed.y-1)<=1||max(ed.x-1,m-ed.y)<=1||max(n-ed.x,ed.y-1)<=1||max(n-ed.x,m-ed.y)<=1){
		if(qibdis(st,ed)<=1)puts("3");
		else puts("2");
	}
	else puts("3");
	return 0;
}
