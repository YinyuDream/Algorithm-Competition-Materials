#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e5+10;
char a[maxn],b[maxn*2];
int n,ans,len[maxn*2];
int l[maxn*2],r[maxn*2];
int main()
{
	scanf("%s",a);
	b[n++]='$';
	b[n++]='#';
	int lenth=strlen(a);
	for(int i=0;i<lenth;i++){
		b[n++]=a[i];
		b[n++]='#';
	}
	n--;
	int mx=0,id=0;
	for(int i=1;i<=n;i++)
	{
		if(i<mx)len[i]=min(len[id*2-i],mx-i);
		else len[i]=1;
		while(b[i-len[i]]==b[i+len[i]]&&i-len[i]>=0){
			l[i+len[i]-1]=max(l[i+len[i]-1],len[i]);
			len[i]++;
		}
		if(i+len[i]>mx)
		mx=len[i]+i,id=i;
	}
	mx=id=n;
	for(int i=n;i>=1;i--)
	{
		if(i>mx)len[i]=min(len[id*2-i],i-mx);
		else len[i]=1;
		while(b[i-len[i]]==b[i+len[i]]&&i+len[i]<=n){
			r[i-len[i]+1]=max(r[i-len[i]+1],len[i]);
			len[i]++;
		}
		if(i-len[i]<mx)
		mx=i-len[i],id=i;
	}
	for(int i=1;i<=n;i++)
	if(b[i]=='#'&&l[i-1]&&r[i+1])
	ans=max(ans,l[i-1]+r[i+1]);
	printf("%d",ans); 
	return 0;
} 
