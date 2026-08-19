#include <cstdio>
#include <cstring>
#define LL long long
#define mod 10007
#define inf 0x3f3f3f3f
#define N 100010
using namespace std;
int dp[12][15][3];
/*dp[pos][k][sta]表示到pos位余数为k,包含13的状态位sta的方案数
dp[pos][k][2]表示非限制条件下到pos位模13余k且已含有13的总个数;
dp[pos][mod][1]表示没含有13但前一位是1且模13余k的总个数;
dp[pos][mod][0]表示没含有13前一位不为1模13余k的总个数

*/
int dig[12];
int dfs(int pos,int pre,int md,int flag,int limit)
{
    if(!pos) return flag&&md==0;
    if(!limit&&flag&&~dp[pos][md][2]) return dp[pos][md][2];
    if(!limit&&!flag&&pre==1&&~dp[pos][md][1]) return dp[pos][md][1];
    if(!limit&&!flag&&pre!=1&&~dp[pos][md][0]) return dp[pos][md][0];
    int up=limit?dig[pos]:9;
    int ans=0;
    for(int i=0;i<=up;i++)
    {
        ans+=dfs(pos-1,i,(md*10+i)%13,flag||(pre==1&&i==3),limit&&i==up);
    }
    if(!limit)
    {
        if(flag)dp[pos][md][2]=ans;
        else if(pre==1)dp[pos][md][1]=ans;
        else dp[pos][md][0]=ans;
    }
    return ans;
}
int solve(int x)
{
    int len=0;
    while(x)
    {
        dig[++len]=x%10;
        x/=10;
    }
    return dfs(len,0,0,0,1);;
}
int main()
{
    int n;
    while(scanf("%d",&n)>0)
    {
        memset(dp,-1,sizeof(dp));
        printf("%d\n",solve(n));
    }
}
