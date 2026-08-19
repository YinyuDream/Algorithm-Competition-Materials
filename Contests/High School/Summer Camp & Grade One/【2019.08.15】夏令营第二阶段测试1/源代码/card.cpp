#include<cstdio>
#include<algorithm>
using namespace std;

int n,sum,cnt,bo;
int a[100010],stack[1000010][2],top,k;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	sum=sum/n;
	for(int i=1;i<=n;i++)
	{
		int temp=a[i]-sum;
		if(temp>0&&top==0)
		{
			a[i+1]+=temp;cnt++;a[i]-=temp;
		}
		else if(temp==0&&top==0)continue;
		else if(temp<0)
		{
			if(a[i+1]+temp>=0)
			{
				a[i+1]+=temp;a[i]-=temp;cnt++;
			}
			else
			{
				stack[++top][0]=i;stack[top][1]=temp;bo=1;	
			}
		}
		else
		{
			while(top!=0)
			{
				a[stack[top][0]]+=min(-stack[top][1],temp);
				cnt+=i-stack[top][0];a[i]-=min(-stack[top][1],temp);
				if(a[stack[top][0]]==sum)top--;
				if(a[i]==sum)i++;
				if(a[i]<sum)break;
			}
		}
	}
	if(bo==0)printf("%d",cnt);
	else printf("%d",n-1);
}
