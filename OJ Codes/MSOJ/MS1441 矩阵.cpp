#pragma GCC optimize(3)
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=(1<<12)+10;
int n,m,opt;
int sum[maxn][maxn];
void update(int x,int y,int num)
{
    for(int i=x;i<=n;i+=i&(-i))
        for(int j=y;j<=m;j+=j&(-j))
            sum[i][j]+=num;
}
int query(int x,int y)
{
    int ans=0;
    for(int i=x;i;i-=i&(-i))
        for(int j=y;j;j-=j&(-j))
            ans+=sum[i][j];
    return ans;
}
int main(){
    scanf("%d%d",&n,&m);
    while(scanf("%d",&opt)!=EOF)
    {
        int a,b,c,d;
        if(opt==1)scanf("%d%d%d",&a,&b,&c),update(a,b,c);
        else scanf("%d%d%d%d",&a,&b,&c,&d),printf("%d\n",query(c,d)-query(c,b-1)-query(a-1,d)+query(a-1,b-1));
    }
    return 0;
}