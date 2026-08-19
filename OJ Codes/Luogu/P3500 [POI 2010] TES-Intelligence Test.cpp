#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,m;
int a[maxn],c[maxn];
vector<int>pos[maxn];
int read(){
	int x=0,sign=1;
	char ch=getchar();
	while(ch>'9'||ch<'0')
	{
		if(ch=='-')sign=-sign;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	x=x*10+ch-48,
	ch=getchar();
	return x*sign;
}
int main(){
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	for(int i=1;i<=n;i++)
		pos[a[i]].push_back(i);
	m=read();
	for(int i=1;i<=m;i++)
	{
		int l=read(),p=0,book=0;
		for(int j=1;j<=l;j++)
		c[j]=read();
		for(int j=1;j<=l;j++)
		{
			auto t=upper_bound(pos[c[j]].begin(),pos[c[j]].end(),p);
			if(t==pos[c[j]].end()){
				book=1;
				puts("NIE");
				break;
			}
			else p=*t;
		}
		if(!book)
		puts("TAK");
	}
	return 0;
}