#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1e6+10;
int n,k,p=1;
int a[maxn],ans[maxn];
char s[maxn];
deque<int>q;
int main(){
	//freopen("mountain.in","r",stdin);
	//freopen("mountain.out","w",stdout);
	scanf("%s%d",s+1,&k);
	n=strlen(s+1);
	k=n-k;
	for(int i=1;i<=n;i++)	
		a[i]=s[i]-'0';
	for(int i=1;i<=n-k;i++){
		while(q.size()&&q.back()>a[i])q.pop_back();
		q.push_back(a[i]);
	}
	for(int i=1;i<=k;i++)
	{
		while(q.size()&&q.back()>a[n-k+i])q.pop_back();
		q.push_back(a[n-k+i]);
		ans[i]=q.front();
		q.pop_front();
	}
	while(ans[p]==0)p++;
	for(int i=p;i<=k;i++)
		printf("%d",ans[i]);
	if(p>k)puts("0");
	return 0;
}
