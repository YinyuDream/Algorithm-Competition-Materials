#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=3e4+10;
int w,n,cnt,l,r;
int a[maxn];
int main(){
	scanf("%d%d",&w,&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	l=1;r=n;
	while(l<=r){
		if(a[l]+a[r]<=w){
			l++;r--;cnt++;
		}else{
			r--;cnt++;
		}
	}
	printf("%d",cnt);
	return 0;
}