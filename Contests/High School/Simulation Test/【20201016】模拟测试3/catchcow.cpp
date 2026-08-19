#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int book[maxn],dis[maxn];
int a,b,T;
queue<int>q;
void bfs()
{
	q.push(a);
	while(q.size()){
		int u=q.front();
		q.pop();
		if(!book[u-1]&&u-1>=0){
			dis[u-1]=dis[u]+1;
			q.push(u-1);
			book[u-1]=1;
		}
		if(!book[u+1]&&u+1<=max(a,b)){
			dis[u+1]=dis[u]+1;
			q.push(u+1);
			book[u+1]=1;
		}
		if(!book[u*2]&&u*2<=max(a,b)*2){
			dis[u*2]=dis[u]+1;
			q.push(u*2);
			book[u*2]=1;
		}
	}
}
int main(){
	scanf("%d",&T);
	while(T--)
	{
		memset(dis,0,sizeof dis);
		memset(book,0,sizeof book);
		scanf("%d%d",&a,&b);
		bfs();
		printf("%d\n",dis[b]);
	}
	return 0;
}
