#include<cstdio>
using namespace std;


int m,n,cnt,p=0;
bool book[120];
int ans;
int main()
{
	scanf("%d%d",&m,&n);
	while(ans<m)
	{
		p++;
		if(book[p]==1)
		{
			p=p%m;//if(p==m)p=0;
			continue;
		}
		
		cnt++;
		if(cnt==n)
		{
			printf("%d ",p);
			cnt=0;
			book[p]=1;
			ans++;
		}
		p=p%m;
	}
	return 0;
}
