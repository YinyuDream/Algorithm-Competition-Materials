#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1.1e7+10;
char a[maxn],b[maxn*2];
int n,ans,len[maxn*2];
int main()
{
	scanf("%s",a);
	b[n++]='$';
	b[n++]='#';
	int lenth=strlen(a);
	for(int i=0;i<lenth;i++)
	{
		b[n++]=a[i];
		b[n++]='#';
	}
	n--;
	int mx=0,id=0;
	for(int i=1;i<=n;i++)
	{
		if(i<mx)
		len[i]=min(len[id*2-i],mx-i);
		else
		len[i]=1;
		while(b[i-len[i]]==b[i+len[i]]&&i-len[i]>=0)
		len[i]++;
		if(i+len[i]>mx)
		{
			mx=len[i]+i;
			id=i;
			ans=max(ans,len[i]);
		}
	}
	printf("%d",ans-1); 
	return 0;
} 
