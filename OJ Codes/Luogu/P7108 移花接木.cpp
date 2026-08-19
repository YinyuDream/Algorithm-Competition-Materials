#include<cstdio>
using namespace std;
const int p=1e9+7;
int T,h,a,b;
int ksm(int a,int b)
{
	if(!b)return 1;
	int c=ksm(a,b/2);
	c=1ll*c*c%p;
	if(b&1)c=1ll*c*a%p;
	return c;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&a,&b,&h);
		if(h==0){
			printf("%d\n",a);
		}else if(a==b){
			printf("%d\n",ksm(a,h+1)%p);
		}else if(a==1){
			printf("%d\n",ksm(b,h)%p);
		}else if(b==1){
			int rr=(1ll*a+h*(a-1))%p;
			printf("%d\n",rr);
		}
	}
	return 0;
}
