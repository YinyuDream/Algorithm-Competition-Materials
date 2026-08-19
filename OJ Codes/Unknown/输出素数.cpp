#include<cstdio>
#include<cmath>
int main()
{
    int k=100;
    scanf("%d",&k); 
    int s=3;int f=0,d;
    printf("2\n");
    while(s<=k)
    {
    for(int i=2;i<=sqrt(s);i++)
        {
        if(s%i==0)d=1;
        else d=0;
        f=f+d;
        }
    if(f==0)printf("%d\n",s);
    s+=2;
    f=0;
    }
    return 0;   
}
