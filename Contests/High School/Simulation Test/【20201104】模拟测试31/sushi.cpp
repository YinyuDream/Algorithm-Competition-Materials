#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=2e6+10;
int T,n,ans,cnt;
char s[maxn];
bool check()
{
	for(int i=1;i<=n;i++)
		s[i+n]=s[i];
	for(int i=1,num=0;i<=n*2;i++,num=0){
		for(int j=1;j<=i+cnt-1;j++)
			if(s[i]=='B')num++;
		if(num==cnt)return true;
	}
	return false;
}
void dfs(int pos)
{
	if(check()){
		ans=min(ans,pos);
		return ;
	}
	if(pos>n*2)return ;
	for(int i=1;i<n;i++){
		swap(s[i],s[i+1]);
		dfs(pos+1);
		swap(s[i],s[i+1]);
	}
	swap(s[n],s[1]);
	dfs(pos+1);
	swap(s[n],s[1]);
}
int main(){
	freopen("sushi.in","r",stdin);
	freopen("sushi.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		ans=0x7f7f7f7f;
		cnt=0;
		scanf("\n%s",s+1);
		n=strlen(s+1);
		for(int i=1;i<=n;i++)
			if(s[i]=='B')
			cnt++;
		dfs(0);
		printf("%d\n",ans);
	}
	return 0;
}
