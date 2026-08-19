#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=3e4+10;
int n,h,cnt;
bool book[maxn];
struct node{
	int b,e,t;
}a[maxn];

bool cmp(node x,node y){
	if(x.e!=y.e)return x.e<y.e;
	else return x.b<y.b;
}
int main(){
	scanf("%d%d",&n,&h);
	for(int i=1;i<=h;i++)
	scanf("%d%d%d",&a[i].b,&a[i].e,&a[i].t);
	sort(a+1,a+h+1,cmp);
	for(int i=1;i<=h;i++){
		int k=0;
		for(int j=a[i].b;j<=a[i].e;j++){
			if(book[j]==1)k++;
		}
		if(k>=a[i].t)continue;
		for(int j=a[i].e;j>=a[i].b;j--){
			if(book[j]==0){
				book[j]=1;
				k++;
				cnt++;
				if(k>=a[i].t)break;
			}
		}
	}
	printf("%d",cnt);
	return 0;
}
