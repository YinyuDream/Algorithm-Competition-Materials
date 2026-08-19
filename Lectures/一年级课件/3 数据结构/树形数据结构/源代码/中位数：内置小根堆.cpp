#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=100000+10;
priority_queue<int ,vector<int>,greater<int> > minq;//小根堆 
priority_queue<int> maxq;//大根堆,默认的 
int maxSize=0,minSize=0;
int a[maxn],n;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	n=(n+1)/2;
	printf("%d\n",a[1]);
	maxq.push(a[1]);
	for(int i=1;i<=n-1;i++){
		//第一步：取一个元素加入小根堆
		if(a[i*2]<maxq.top()){
			minq.push(maxq.top());
			maxq.pop(); maxq.push(a[i*2]);
		} else minq.push(a[i*2]);
		//第二步：取第二个元素加入大根堆
		if(a[i*2+1]>minq.top()){
			maxq.push(minq.top());
			minq.pop(); minq.push(a[i*2+1]);
		} else maxq.push(a[i*2+1]);
		//第三步：输出大根堆堆顶元素 
		printf("%d\n",maxq.top());
	}
	return 0;
}
