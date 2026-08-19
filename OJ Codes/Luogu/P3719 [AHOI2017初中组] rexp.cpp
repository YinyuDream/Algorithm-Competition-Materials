#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e5+10;
int len,cnt,top1,top2;
char a[maxn];
char stack[maxn];
int num[maxn];
int main()
{
    //freopen("sinple.in","r",stdin);
    //freopen("sinple.out","w",stdout);
    scanf("%s",a);
    len=strlen(a);
    for(int i=0;i<len;i++)
    {
         
        if(a[i]=='a')cnt++;
        if(i==len-1&&a[i]=='a')num[++top2]=cnt;
        if(a[i]=='|')
        {   
            if(cnt!=0)
            {
                num[++top2]=cnt;
                cnt=0;
            }
            if(stack[top1]=='|')
            {
                int tmp=num[top2--];
                num[top2]=max(tmp,num[top2]);
            }
            else
            {   
                stack[++top1]='|';  
            }
        }
        if(a[i]=='(')
        {
            if(cnt!=0)num[++top2]=cnt;
            cnt=0;
            stack[++top1]='(';
             
        }
        if(a[i]==')')   
        {
            if(cnt!=0)
            {
                top2++;
                num[top2]=cnt;cnt=0;
            }
            if(stack[top1]=='|')
            {
                num[top2-1]=max(num[top2],num[top2-1]);
                top2--;top1-=2;continue;
            }
            if(num[top2-1]!=0&&stack[top1-1]!='|')
            {
                num[top2-1]=num[top2-1]+num[top2];top2--;   
            }
            if(stack[top1-1]=='|')top1-=1;
            else top1-=2;
        }
    }
    if(stack[top1]=='|')printf("%d",max(num[1],num[2]));
    else if(top2!=1&&stack[top1]!='|')printf("%d",num[1]+num[2]);
    else if(top2==1)printf("%d",num[1]);
    return 0;
}