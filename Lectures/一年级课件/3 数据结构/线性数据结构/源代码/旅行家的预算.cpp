#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=100000+10;
double d1,c,d2,p,maxlen;
int n;
double list[maxn],op[maxn];
double ans=0;
double que_p[maxn],que_c[maxn]; 
int head,tail;
int main()
{
	double d,cc;
	scanf("%lf%lf%lf%lf",&d1,&c,&d2,&p);
	scanf("%d",&n);
	maxlen=c*d2;
	for(int i=1;i<=n;i++){
		scanf("%lf%lf",&list[i],&op[i]);
		if(list[i]-list[i-1]>maxlen) { 
			printf("No Solution\n");return 0;
		}
	}
	list[n+1]=d1;
	head=tail=0;
	que_p[++tail]=p;que_c[tail]=c;//起点油箱加满，入队(价格，油量) 
	for(int i=1;i<=n+1;i++) {//枚举每一个加油站 
		//第一：计算从上一站开过来需要的费用
		cc=0; 
		d=list[i]-list[i-1];//算出两点之间的距离
		while(que_c[head]*d2<d){
			ans+=que_c[head]*que_p[head];
			d-=que_c[head]*d2;
			cc+=que_c[head];
			head++;
		}
		ans+=que_p[head]*d/d2;
		que_c[head]-=(d/d2);
		cc+=(d/d2);
		if(i==n+1) break;
		//第二：从队尾开始用当前加油站的油去替换油箱里比当前价位高的油。
		while(que_p[tail]>op[i]){
			cc+=que_c[tail--];
		}
		que_p[++tail]=op[i];que_c[tail]=cc;
	}
	printf("%.2f\n",ans);
	return 0;
} 
