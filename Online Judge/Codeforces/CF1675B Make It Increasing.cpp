#include<cstdio>
using namespace std;
const int maxn=1e2+10;
int T,n,cnt,flag;
int a[maxn];
int main(){
	scanf("%d",&T);
	while(T--){
		flag=cnt=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=n-1;i>=1;i--)
			while(a[i]>=a[i+1]&&a[i])
				a[i]/=2,cnt++;
		for(int i=1;i<n;i++)
			if(a[i]==a[i+1])
				cnt=-1;
		printf("%d\n",cnt);
	}
	return 0;
}