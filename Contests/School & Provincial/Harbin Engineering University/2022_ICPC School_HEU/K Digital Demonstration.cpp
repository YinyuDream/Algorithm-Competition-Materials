#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10; 
int arr[maxn],ans[maxn],book[maxn],num,T;
int fr1[maxn],fr2[maxn];
struct node{
	int num,step;
	node(int _num,int _step){
		num=_num,step=_step;
	}
};
queue<node>q;
void work(int x){
	int sq=sqrt(x);
	for(int i=1;i<=sq;i++){
		if(x%i==0){
			arr[++num]=i+x/i;
			if(!book[arr[num]])
				fr1[arr[num]]=i,
				fr2[arr[num]]=x/i;
		}	
	}
}
int main(){
	memset(ans,0x7f,sizeof ans);
	ans[114514]=0,book[114514]=1;
	q.push(node(114514,0));
	while(q.size()){
		node m=q.front();
		ans[m.num]=m.step;
		q.pop();
		num=0;
		if(m.step<=200000)
			work(m.num);
		for(int i=1;i<=num;i++)
			if(!book[arr[i]])
				q.push(node(arr[i],m.step+1)),book[arr[i]]=1;
	}
	scanf("%d",&T);
	if(ans[T]==0x7f7f7f7f)puts("-1");
	else{
		printf("%d\n",ans[T]);
		while(T!=114514){
			printf("%d %d\n",fr1[T],fr2[T]);
			T=fr1[T]*fr2[T];
		}
	}
	return 0;
}