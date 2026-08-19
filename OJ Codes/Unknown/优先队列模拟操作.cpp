#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
struct node{
	int sum;
	friend bool operator <(node x,node y){
		return x.sum>y.sum;
	}	
};
priority_queue<node> q;
int main()
{
	int n;
	 printf("优先队列程序\n");
	 printf("按1接受整数并入队\n按2打印队顶元素\n按3出队\n按4打印队列长度\n按5打印队列是否为空\n按6查看操作方法\n按7退出\n");
	 while(1){
	 	scanf("%d",&n);
	 	if(n==1){
	 		node a;
	 		printf("输入要入队的整数\n");
	 		scanf("%d",&a.sum);
	 		q.push(a);
			printf("进入下个操作\n"); 
	 	}else if(n==2){
	 		printf("队顶元素:%d\n",q.top().sum);
	 		printf("进入下个操作\n");
	 	}else if(n==3){
	 		q.pop();
	 		printf("进入下个操作\n");
	 	}else if(n==4){
	 		printf("队列长度:%d\n",q.size());
	 		printf("进入下个操作\n");
	 	}else if(n==5){
	 		if(q.empty())printf("ture\n");
	 		else printf("false\n");
	 		printf("进入下个操作\n");
	 	}else if(n==6){
	 	printf("按1接受整数并入队\n按2打印队顶元素\n按3出队\n按4打印队列长度\n按5打印队列是否为空\n按7退出\n");
		printf("进入下个操作\n");	
	 	}else{
	 	break; 
		}
	 }
	 return 0; 
}
