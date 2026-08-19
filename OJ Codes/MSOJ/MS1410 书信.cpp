#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int top;
ll t,n;
ll a[maxn];
int main(){
	//freopen("letter.in","r",stdin);
	//freopen("letter.out","w",stdout);
	scanf("%lld",&n);
	t=n;
	for(int i=2;i<maxn;i++){
		if(t%i==0){
			a[++top]=i;
			while(t%i==0)
			t/=i;
		}
		if(t==1)break;
	}
	if(t>1)a[++top]=t;
	for(int i=1;i<=top;i++)
		n=n/a[i]*(a[i]-1);
	printf("%lld",n);
}