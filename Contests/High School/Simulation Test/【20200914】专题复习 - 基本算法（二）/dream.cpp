#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,m,ans,j=1;
int t[maxn],book[maxn];
struct node{
    int l,r;
}a[maxn];
bool cmp(node a,node b)
{
    return a.l<b.l;
}
priority_queue<int,vector<int>,greater<int> >q;
int main()
{
    //freopen("dream.in","r",stdin);
    //freopen("dream.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&a[i].l,&a[i].r);
    for(int i=1;i<=m;i++)
        scanf("%d",&t[i]);
    sort(a+1,a+n+1,cmp);
    sort(t+1,t+m+1);
    for(int i=1;i<=m;i++)
    {
    	for(;a[j].l<=t[i]&&j<=n;j++)
    		q.push(a[j].r);
    	while(q.size()&&q.top()<t[i])q.pop();
    	if(q.size()){
    		ans++;
    		q.pop();
    	}
    }
    printf("%d",ans);
}
