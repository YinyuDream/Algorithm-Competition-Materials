#include<cstdio>
using namespace std;
const int maxn=1e6+10;
char opt;
int n;
int base[maxn],a[maxn],b[maxn],ans[maxn];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&base[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	scanf("\n%c",&opt);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	if(opt=='+'){
		for(int i=n;i;i--){
			ans[i]+=a[i]+b[i];
			ans[i-1]+=ans[i]/base[i];
			ans[i]%=base[i];
		}
		for(int i=1;i<=n;i++)
			printf("%d ",ans[i]);
	}else{
		for(int i=n;i;i--){
			ans[i]=a[i]-b[i];
			while(ans[i]<0){
				ans[i]+=base[i];
				a[i-1]--;
			}
		}
		for(int i=1;i<=n;i++)
			printf("%d ",ans[i]);
	}
	return 0;
}