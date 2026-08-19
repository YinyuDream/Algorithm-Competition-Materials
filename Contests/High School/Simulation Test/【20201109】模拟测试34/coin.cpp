#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,k,top;
int num[maxn],a[maxn],f[maxn],g[maxn];
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    f[0]=1;
    for(int i=1;i<=n;i++)
        for(int j=k;j>=a[i];j--)
            f[j]+=f[j-a[i]];
    for(int i=1;i<=n;i++){
        memset(g,0,sizeof(g));
        for (int j=0;j<=k;j++)
        if (j-a[i]>=0)g[j]=f[j]-g[j-a[i]];
        else g[j]=f[j];
        if (g[k]==0)num[++top]=a[i];
    }
    top=unique(num+1,num+top+1)-num-1;
    printf("%d\n",top);
    for(int i=1;i<=top;i++)
        printf("%d ",num[i]);
}
