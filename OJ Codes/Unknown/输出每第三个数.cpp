#include<cstdio>
using namespace std;


int m,n,cnt,p=0;
bool book[120];
int ans;
int main()
{
	scanf("%d",&m);
	book[1]=1;
	n=3;
	printf("1 ");
	while(ans<m)
	{
		p++;
		if(book[ans]==1)
		{
			ans=ans%m;
			continue;
		}
		
		cnt++;
		if(cnt==3)
		{
			printf("%d ",ans);
			cnt=0;
			book[ans]=1;	
		}
		ans++;
		p=p%m;
	}
	return 0;
}
