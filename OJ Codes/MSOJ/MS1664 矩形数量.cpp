#include<cstdio>
#pragma GCC optimize(3)
using namespace std;
const int maxn=5e4+10;
int n,m,L,R;
char s[maxn];
int a[50][maxn];
long long ans;
inline int sum(int a1,int b1,int a2,int b2)
{
	return a[a2][b2]-a[a1-1][b2]-a[a2][b1-1]+a[a1-1][b1-1];
}
int main(){
	//freopen("data.txt","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("\n%s",s+1);
        for(int j=1;j<=m;j++)
            a[i][j]=s[j]-'0';
    }
    scanf("%d%d",&L,&R);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
    for(int i=1;i<=n;i++)//上端点 
    	for(int j=i;j<=n;j++)//下端点 
    	{
    		int l1=1,l2=1; 
    		for(int k=1;k<=m;k++)//右端点
			{
				while(sum(i,l1,j,k)>R&&l1<=k)l1++;
				while(sum(i,l2,j,k)>=L&&l2<=k)l2++;
				ans+=1ll*l2-l1;
			}
    	}
    printf("%lld",ans);
    return 0;
}