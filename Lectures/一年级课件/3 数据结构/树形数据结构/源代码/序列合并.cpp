#include<cstdio>
#include<cstring>
#include<queue> 
#include<algorithm>
using namespace std;
const int maxn=100000+10;
struct node{
	int x,y,sum;
	node(int xx,int yy,int s){x=xx;y=yy;sum=s; }
	friend bool operator < (node xx,node yy) 
	{return xx.sum>yy.sum;}//小根堆 
};
priority_queue<node> q;
int a[maxn],b[maxn],n;
int cnt=0;
inline int read(){
	int x=0,f=1;
	char ch; ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		x=x*10+ch-'0';ch=getchar();
	}
	return x*f; 
} 
int main()
{
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++) b[i]=read();
	q.push(node(1,1,a[1]+b[1]));
	while(cnt<=n){
		node no=q.top();q.pop();//取出堆顶元素
		printf("%d\n",no.sum);//输出堆顶元素的值
		if(no.y<n) q.push(node(no.x,no.y+1,a[no.x]+b[no.y+1]));
		if(no.y==1 && no.x<n) q.push(node(no.x+1,no.y,a[no.x+1]+b[no.y]));
		cnt++;
	}
	return 0;
} 
