#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=1e5+10;
int n;
int a[maxn];
int f[maxn],top;
int cmp(int x,int y){
	return x>y;
}
int main(){
	while(scanf("%d",&a[++n])!=EOF);
	n--;
	for(int i=1;i<=n;i++){//最长不上升子序列 
		if(f[top]>=a[i]||top==0)f[++top]=a[i];
		else{
			int k=upper_bound(f+1,f+top+1,a[i],cmp)-f;
			f[k]=a[i]; 
		}
	}
	printf("%d\n",top),top=0;
	memset(f,0,sizeof f);
	for(int i=1;i<=n;i++){//最长上升子序列 
		if(f[top]<a[i]||top==0)f[++top]=a[i];
		else{
			int k=lower_bound(f+1,f+top+1,a[i])-f;
			f[k]=a[i]; 
		}
	}
	printf("%d",top);
	return 0;
}