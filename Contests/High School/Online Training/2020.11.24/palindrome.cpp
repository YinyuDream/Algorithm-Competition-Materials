#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int T,n;
char a[maxn];
namespace subtask1{
	int f[maxn][2][2],ans=0x3f3f3f3f;//考虑到i，当前位0/1，上一位0/1 
	void work()
	{
		memset(f,0x3f,sizeof f);
		f[1][0][0]=0,f[1][1][0]=1;
		scanf("%s",a+1);
		for(int i=2;i<=n;i++){
			if(a[i]==a[i-1]&&a[i]!=a[i-2]){
				f[i][0][1]=min(f[i-1][1][0],f[i-1][1][1]);
				f[i][1][0]=min(f[i-1][0][0],f[i-1][0][1])+1;
				f[i][1][1]=min(f[i-1][1][0],f[i-1][1][1])+1;
			}else if(a[i]==a[i-2]){
				f[i][0][0]=f[i-1][0][1];
				f[i][0][1]=f[i-1][1][1];
				f[i][1][0]=min(f[i-1][0][0],f[i-1][0][1])+1;
				f[i][1][1]=min(f[i-1][1][0],f[i-1][1][1])+1;
			}else{
				f[i][0][0]=min(f[i-1][0][0],f[i-1][0][1]);
				f[i][0][1]=min(f[i-1][1][0],f[i-1][1][1]);
				f[i][1][0]=min(f[i-1][0][0],f[i-1][0][1])+1;
				f[i][1][1]=min(f[i-1][1][0],f[i-1][1][1])+1;
			}
		}
		ans=min(ans,f[n][0][0]);
		ans=min(ans,f[n][0][1]);
		ans=min(ans,f[n][1][0]);
		ans=min(ans,f[n][1][1]);
		printf("%d",ans);
	}
}
int main(){
	freopen("palindrome.in","r",stdin);
	freopen("palindrome.out","w",stdout);
	scanf("%d%d",&T,&n);
	if(T==1)subtask1::work();
	//else subtask2::work();
	return 0;
}
