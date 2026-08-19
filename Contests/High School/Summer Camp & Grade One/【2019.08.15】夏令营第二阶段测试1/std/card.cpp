#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e5+10;
int n;
int a[maxn];//用来接收每个数 
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int sum=0,ans=0,val=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	val=sum/n;//求平均值 
	
	
	//每个人依次比较，如果比平均数多，多的给后面那个人 
	 //如果不够平均数，就管后面的人要。 
	for(int i=1;i<=n-1;i++){
		if(a[i]!=val){      
			ans++;
			a[i+1]+=a[i]-val;
		}
	}
	printf("%d\n",ans);
	return 0;
}
