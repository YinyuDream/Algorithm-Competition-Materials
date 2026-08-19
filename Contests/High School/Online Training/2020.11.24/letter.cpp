#include<cstdio>
#include<stack>
#include<cstring>
using namespace std;
const int maxn=5e3+10;
int n,ans,top,book[maxn];
char a[maxn],b[maxn][maxn],tp[maxn],st[maxn];
void dfs(int cnt,int step)
{
	if(step==n+1){
		
		ans=min(ans,cnt+top);
		return ;
	}
	if(cnt>3*n||ans<cnt+n-step)return ;
	if(top&&st[top]==a[step])dfs(cnt+1,step+1);
	char c;
	if(top)c=st[top],book[c]=0,top--,dfs(cnt+1,step),st[++top]=c,book[c]=1;
	if(!book['A'])st[++top]='A',book['A']=1,dfs(cnt+1,step),top--,book['A']=0;
	if(!book['B'])st[++top]='B',book['B']=1,dfs(cnt+1,step),top--,book['B']=0;
	if(!book['C'])st[++top]='C',book['C']=1,dfs(cnt+1,step),top--,book['C']=0;
}
void dfs2(int cnt,int step)
{
	if(step==n+1){
		ans=min(ans,cnt+top);
		return ;
	}
	if(cnt>3*n||ans<cnt+n-step)return ;
	st[++top]=a[step],book[a[step]]++,dfs2(cnt+2,step+1),top--,book[a[step]]--;
	if(book[a[step]]){
		while(st[top]!=a[step])book[st[top]]--,--b[step][++tp[step]]=st[top--],cnt++;
		dfs2(cnt+1,step+1);
		while(tp[step])st[++top]=b[step][tp[step]--],book[st[top]]++,cnt--;
	}
}
void work()
{
	ans=strlen(a+1);
	for(int i=1;i<=n;i++){
		if(!book[a[i]]){
			st[++top]=a[i];
			book[a[i]]++;
			ans++;
		}else{
			while(st[top]!=a[i]){
				book[st[top--]]--;
				ans++;
			}
			
		}
	}
	printf("%d",ans+top);
}
int main(){
	freopen("letter.in","r",stdin);
	freopen("letter.out","w",stdout);
	scanf("%s",a+1);
	n=strlen(a+1);
	if(n<=36)ans=0x7f7f7f7f,dfs2(0,1),printf("%d",ans);
	else work();
	return 0;
}
