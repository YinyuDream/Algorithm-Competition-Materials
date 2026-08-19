#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1000+10;
struct node{
	int num,next;
} list[maxn*2];
int n,m,head=0,k=0;
void insert(int val){//插入元素val后，保证序列依然从小到大有序 
	list[++k].num=val;list[k].next=0;
	if(head==0) {head=k; return;} 
	if(list[head].num>val){
		list[k].next=head;
		head=k; return; 
	}
	int p=head,q;
	while(p!=0){
		q=list[p].next;
		if(list[p].num<val && (val<list[q].num) || q==0){
			list[k].next=q;
			list[p].next=k;
			return;
		}
		p=list[p].next;
	}
}
void select(){//遍历整个序列，从小到大输出 
	int p=head;
	while(p!=0){
		printf("%d ",list[p].num);
		p=list[p].next;
	} printf("\n");
}
int query(int val){//查询给定的值val是第几小 
	int p=head,cnt=0;
	while(p!=0){
		if(list[p].num==val) return ++cnt;
		p=list[p].next; cnt++;
	}
	return -1;
}
void del(int val){//删除指定的元素val 
	int p=head,q;
	if(list[head].num==val) { head=list[p].next; return; }
	while(p!=0){
		q=list[p].next;
		if(list[q].num==val){
			list[p].next=list[q].next; return;
		}
		p=list[p].next;
	}
}
int main()
{
	int temp,opt,val;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&temp),insert(temp);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&opt,&val);
		if(opt==1) insert(val);
		if(opt==2) {
			int cnt=query(val);
			if(cnt==-1) printf("NO\n");
			else printf("%d\n",cnt);
		}
		if(opt==3) del(val);
		if(opt==4) select();
	}
	select();
	return 0;
}
