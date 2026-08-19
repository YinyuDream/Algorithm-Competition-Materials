#include<cstdio>
#include<cmath>
using namespace std;
int n,m,k,ans;
bool check(int a1,int a2,int b1,int b2,int c1,int c2)//x1,y1,x2,y2,x3,y3
{
	if((a1-b1)*(b2-c2)==(a2-b2)*(b1-c1))return false;
	double len1=sqrt((a1-b1)*(a1-b1)+(a2-b2)*(a2-b2)),
		   len2=sqrt((a1-c1)*(a1-c1)+(a2-c2)*(a2-c2)),
		   len3=sqrt((b1-c1)*(b1-c1)+(b2-c2)*(b2-c2)),
		   p=(len1+len2+len3)/2,S=sqrt(p*(p-len1)*(p-len2)*(p-len3));
	if(S!=(int)S)return false;
	int t=S;
	if(t%k!=0)return false;
	return true;
}
int main(){
	freopen("delta.in","r",stdin);
	freopen("delta.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int a1=0;a1<=n;a1++)
		for(int a2=0;a2<=m;a2++)
			for(int b1=0;b1<=n;b1++)
				for(int b2=0;b2<=m;b2++)
					for(int c1=0;c1<=n;c1++)
						for(int c2=0;c2<=m;c2++)
							if(check(a1,a2,b1,b2,c1,c2))
								ans++;
	printf("%d",ans);
	return 0;
}
