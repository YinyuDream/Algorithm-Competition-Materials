#include <cstdio>
int a[100+10][100+10];//a[i][j]=1：第i个人喜欢第j本书，0表示不喜欢
int b[100+10];//记录分配方案:b[i]是第i个人借第b[i]本书
bool book[100+10];
/*book[i]表示第i本书是被人借走的意思,book[i]=true;表示没有借走，
book[i]=false表示已经借走 */ 
int n;
void dfs(int i)
{
    if(i==n+1)//输出n个人。借书方案 
    {
        bool first=true;
        for(int k=1;k<=n;k++)
        {
            if(first) printf("%d",b[k]); else printf(" %d",b[k]);
        }
        printf("\n");
    } 
    else
    {
        for(int j=1;j<=n;j++)
        {
            if(a[i][j]==1 && book[j]) //判断第i个人是否可以借第j本书 
            {
               b[i]=j; //表示第i个人借了第j本书 
               book[j]=false; //第j本书已被借出 
               dfs(i+1);//找下一个人可以借的书 
               book[j]=true; //回溯意味，再次标记第j本书 没有被借出
            }
        } 
    }
} 

int main()
{ 
    //读入数据 
    //freopen("lend.in","r",stdin);
    //freopen("lend.out","w",stdout);
    //memset(a,sizeof(a),0); //数组初始化
    //memset(b,sizeof(b),0);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        book[i]=true;
    } 
    for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)
        scanf("%d",&a[i][j]);
        
    /*模拟借书过程
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
        printf("%d ",a[i][j]); 
      printf("\n");
    }
    */
    dfs(1);
    while(1);
    return 0;
}
