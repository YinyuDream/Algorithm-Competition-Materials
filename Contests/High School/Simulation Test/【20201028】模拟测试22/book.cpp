#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,p,q,x,y,ans=0x7f7f7f7f,d,t;
char a[maxn],s[maxn];
int work(int l,int r,int sum)
{
	int cnt=0;
	for(int i=l;i<=r;i++)
		s[i]=a[i];
	if(sum<0){
		for(int i=r;i>=l&&sum<0;i--){
			if(s[i]=='+'){
				s[i]='-';
				sum+=2;
				cnt+=x;
			}
		}
	}else{
		for(int i=l;i<=r&&sum>0;i++)
			if(s[i]=='-'){
				s[i]='+';
				sum-=2;
				cnt+=x;
			}
	}
	int minx=0,sumq=p;
	for(int i=l;i<=r;i++)
		sumq=sumq+(s[i]=='+'?1:-1),minx=min(minx,sumq);
	cnt+=-x*minx;
	return cnt;
}
int main(){
	freopen("book.in","r",stdin);
	freopen("book.out","w",stdout);
	scanf("%d%d%d%d%d\n%s",&n,&p,&q,&x,&y,a+1);
	d=q-p;
	for(int i=1;i<=n;i++){
		a[i+n]=a[i];
		if(a[i]=='-')t--;
		else t++;
	}
	for(int i=1;i<=n;i++)
		ans=min(ans,work(i,i+n-1,d-t)+y*((n-i+1)%n));
	printf("%d",ans);
	return 0;
}
