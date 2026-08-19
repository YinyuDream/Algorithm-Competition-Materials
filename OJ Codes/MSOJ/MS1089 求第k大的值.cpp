#include<cstdio>
using namespace std;
int n,m;
int a[1000000+10];
int maxn,temp; 
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        maxn=i;
        for(int j=i+1;j<=n;j++)
        {
            if(a[j]>a[maxn])
            {
                maxn=j;     
            }   
        }
            temp=a[i];
            a[i]=a[maxn];
            a[maxn]=temp;   
    }
    printf("%d ",a[m]);
    return 0;
}