#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=100000+10;
struct node1{
	int x;
	node1(int xx) {x=xx;}
	friend bool operator<(node1 a, node1 b){
		return a.x>b.x;//最小值优先 
	}
	/*bool operator < (const node1 &a) const { 
		return x>a.x;//最小值优先 
	}*/
};
struct node2{
	int x;
	node2(int xx){x=xx;}
	friend bool operator<(node2 a,node2 b){
		return a.x<b.x;//结构体中，x大的优先级高     
	}
	/*bool operator < (const node2 &a) const { 
		return x<a.x;//最大值优先 
	}*/
};
priority_queue<node1> minq;//小根堆 
priority_queue<node2> maxq;//大根堆,默认的 
int maxSize=0,minSize=0;
int a[maxn],n;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	n=(n+1)/2;
	printf("%d ",a[1]);
	maxq.push(node2(a[1]));
	for(int i=1;i<=n-1;i++){
		//第一步：取一个元素加入小根堆
		if(a[i*2]<maxq.top().x){
			minq.push(node1(maxq.top().x));
			maxq.pop(); maxq.push(node2(a[i*2]));
		} else minq.push(node1(a[i*2]));
		//第二步：取第二个元素加入大根堆
		if(a[i*2+1]>minq.top().x){
			maxq.push(node2(minq.top().x));
			minq.pop(); minq.push(node1(a[i*2+1]));
		} else maxq.push(node2(a[i*2+1]));
		//第三步：输出大根堆堆顶元素 
		printf("%d ",maxq.top().x);
	}
	return 0;
}
