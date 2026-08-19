#include<stack>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
const int maxn=1e3+10;
int T,n;
int book[maxn];
struct node{
	int a,b,t;
}z[maxn];
stack<int>sta;
stack<pair<int,int> >st;
int query(char *s)
{
	int t=strlen(s);
	if(s[2]=='1')return 0;
	if(s[5]==')')return s[4]-'0';
	else return (s[4]-'0')*10+s[5]-'0';
}
int change(char *a,char *b)
{
	int t1,t2;
	if(a[0]=='n')t1=-1;
	else t1=atoi(a);
	if(b[0]=='n')t2=-1;
	else t2=atoi(b);
	if(t1==-1&&t2!=-1)return -1;
	else if(t1!=-1&&t2==-1)return 1;
	else{
		if(t1>t2)return -1;
		else return 0;
	}
}
int check(int x)
{
	while(sta.size())sta.pop();
	memset(book,0,sizeof book);
	int tmp=0;
	for(int i=1;i<=n;i++)
	{
		tmp+=z[i].a;
		if(tmp<0)return -1;
	}
	if(tmp)return -1;
	for(int i=1;i<=n;i++)
	{
		if(z[i].a==1){
			if(book[z[i].b]==1)return -1;
			sta.push(z[i].b);
			book[z[i].b]=1;
		}else{
			book[sta.top()]=0;
			sta.pop();
		}
	}
	for(int i=0;i<=n+1;i++)
	{
		if(z[i].a==1)st.push(make_pair(i,0));
		else{
			if(z[st.top().first].t==-1)st.top().second=0;
			else if(z[st.top().first].t==0);
			else st.top().second++;
			int tp=st.top().second;
			st.pop();
			if(i==n+1){
				return tp==x;
			}
			st.top().second=max(st.top().second,tp);
		}
	}
}
int main(){
	scanf("%d",&T);
	while(T--)
	{
		char s[15];
		scanf("%d %s",&n,s);
		int t=query(s);
		for(int i=1;i<=n;i++)
		{
			char a,b,st[15],ed[15];
			scanf("\n%c",&a);
			if(a=='F')
				scanf(" %c%s%s",&b,st,ed);
			if(a=='F')
			{
				z[i].a=1;z[i].b=b-'a';
				z[i].t=change(st,ed);
			}
			else z[i].a=-1;
		}
		z[0].a=1,z[0].b=128,z[0].t=0;z[n+1].a=-1;
		t=check(t);
		if(t==1)puts("Yes");
		else if(t==0)puts("No");
		else puts("ERR");
	}
	return 0;
}
