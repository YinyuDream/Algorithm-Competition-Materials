#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e2+10,maxl=1e6+10;
int n,len[maxn],lent;
char s[maxl],t[maxl];
int cnt1,cnt2,cnt3;
namespace subtask1{
	void work()
	{
		for(int i=1;i<=n;i++){
		
			int flag=1;
			for(int j=1;j<=lent;j++)
				if(t[j]!=s[j+len[i-1]]&&t[j]!='?')
					flag=0;
			for(int j=1;j<=len[i]-len[i-1];j++)
				printf("%d",j==lent?flag:0);
			puts("");
		}
	}
}
namespace subtask2{
	int cnt,top,ans[maxn][maxn*maxn],all_dis[maxn];
	char st[maxn],all[10][maxn];
	void dfs(int step)
	{
		if(step==lent+1){
			cnt++;
			for(int i=1;i<=top;i++)
				all[cnt][i]=st[i];
			all_dis[cnt]=top;
			return ;
		}      
		if(t[step]=='['){
			int now=step;
			while(t[now]!=']')
				now++;
			for(int i=step+1;i<now;i++)
				st[++top]=t[i];
			dfs(now+1);
			top-=now-step-1;
			dfs(now+1);
		}else{
			st[++top]=t[step];
			dfs(step+1);
			top--;
		}
	}
	void work()
	{
		dfs(1);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=cnt;j++){
				int flag=1;
				for(int k=1;k<=all_dis[j];k++)
					if(s[k+len[i-1]]!=all[j][k])flag=0;
				ans[i][all_dis[j]]=max(ans[i][all_dis[j]],flag);
			}
		}
		for(int i=1;i<=n;i++,puts(""))
			for(int j=1;j<=len[i]-len[i-1];j++)
				printf("%d",ans[i][j]);
	}
}
int main(){
	freopen("walking.in","r",stdin);
	freopen("walking.out","w",stdout);
	scanf("%s\n%d",t+1,&n);
	lent=strlen(t+1);
	for(int i=1;i<=n;i++){
		scanf("%s",s+len[i-1]+1);
		len[i]=len[i-1]+strlen(s+len[i-1]+1);
	}
	for(int i=1;i<=lent;i++){
		if(t[i]=='*')cnt1++;
		if(t[i]=='?')cnt2++;
		if(t[i]=='[')cnt3++;
	}
	if(cnt1+cnt2+cnt3==0||(cnt2&&!cnt1&&!cnt3))subtask1::work();
	else if(!cnt2&&!cnt1&&cnt3)subtask2::work();
	return 0;
}
