#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,m,k,lst,top,sum;
int a[maxn],b[maxn],c[maxn];
int col[maxn],num[maxn];
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	for(int i=1;i<=k;i++)
		scanf("%d",&c[i]);
	for(int i=1;i<=n;i++)
		if(b[i]!=b[i+1])
			col[++top]=b[i],num[top]=i-lst,lst=i;
	for(int i=1;i<=k;i++)
	{
		if(top==2){
			if(num[top]+1==a[col[top]]&&num[top-1]+1==a[col[top-1]]&&col[top-1]==c[i]){
				printf("Win\n%d",i);
				return 0;
			}
		}else if(top==1){
			if(c[i]==col[top]&&num[top]+2==a[col[top]]){
				printf("Win\n%d",i);
				return 0;
			}
		}
		if(c[i]!=col[top])col[++top]=c[i],num[top]=1;
		else{
			
			num[top]++;
			if(num[top]==a[col[top]]){
				num[top]-=a[col[top]];
				if(!num[top])top--;
			}
			if(!top){
				printf("Win\n%d",i);
				return 0;
			}
		}
	}
	for(int i=1;i<=top;i++)
		sum+=num[i];
	printf("Lose\n%d",sum);
	return 0;
}