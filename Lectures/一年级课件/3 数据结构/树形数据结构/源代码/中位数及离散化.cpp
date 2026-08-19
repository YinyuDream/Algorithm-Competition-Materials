#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
/*struct node {     
　　int x, y;     
　　friend bool operator<(node a, node b){         
　　　　return a.x > b.x; //结构体中，x小的优先级高     
　　}
};
priority_queue<node>q; //定义方法*/ 
priority_queue<int> maxq;//大根堆,默认的 
priority-queue<greater<int> > minq;//小根堆，greater表示系统重载小于 
int maxSize=0,minSize=0,;
int a[maxn];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	n=(n+1)/2;
	printf("%d ",a[1]);
	maxq.push(a[1]);
	for(int i=2;i<=n;i++){
		//第一步：取一个元素加入小根堆
		if(a[i*2]<maxq.top()){
			minq.push(maxq.top());
			maxq.pop(); maxq.push(a[i*2]);
		} else minq.push(a[i*2]);
		//第二步：取第二个元素加入大根堆
		if(a[i*2+1]>minq.top()){
			maxq.push((minq.top));
			min.pop(); minq.push(a[i*2+1]);
		} else maxq.push(a[i*2+1]);
		//第三步：输出大根堆堆顶元素 
		printf("%d",&maxq.top());
	}
	return 0;
}

void insert(int x){//从x位置 
	while(x<=n){
		c[x]++;//仅统计个数 
		x+=x&(-x);
	}
}
int get(int x){
	int ans=0;
	while(x>0){
		ans+=c[x];
		x-=x&(-x);
	}
	return ans;
}
int ans=0;
for(int i=n;i>=1;i--){
	ans+=get(a[i]-1);
	insert(a[i]);
}

#include<algorithm>

#include<algorithm> // 头文件 
//n:原数组大小; num原数组中的元素; 
//lsh:离散化的数组; cnt:离散化后的数组大小 
int lsh[MAXN],cnt,num[MAXN],n;
for(int i=1; i<=n; i++) {
	scanf("%d",&num[i]);
	lsh[i] = num[i];
}
sort(lsh+1,lsh+n+1);
cnt = unique(lsh+1,lsh+n+1)-lsh-1;//去重函数 
for(int i=1; i<=n; i++)
	num[i] = lower_bound(lsh+1,lsh+cnt+1,num[i])-lsh;	
struct Node {
	int data,id;
	bool operator < (const Node &a) const {
		return data < a.data;
	}
};
Node num[MAXN];
int rank[MAXN],n;
for(int i=1; i<=n; i++) {
	scanf("%d",&num[i].data); num[i].id = i;
}
sort(num+1 , num+n+1);
for(int i=1; i<=n; i++) rank[num[i].id] = i;


