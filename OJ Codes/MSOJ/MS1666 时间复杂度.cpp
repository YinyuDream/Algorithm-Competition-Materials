#include<cstdio>
#include<stack>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e3+10;
int T,n;
struct node{
	int a,b,t;
}z[maxn];
int book[maxn];
stack<int>sta;
stack<pair<int,int> >st;
int query(char *s)
{
	if(s[2]=='1')return 0;
	else if(s[5]==')')return s[4]-'0';
	else return (s[4]-'0')*10+s[5]-'0';
}
int change(char *a,char *b)
{
	int t1,t2;
	if(a[0]=='n')t1=-1;
	else t1=atoi(a);
	if(b[0]=='n')t2=-1;
	else t2=atoi(b);
	if(t1==-1&&t2==-1)return 0;
	else if(t1==-1&&t2!=-1)return -1;
	else if(t1!=-1&&t2==-1)return 1;
	else{
		if(t1<=t2)return 0;
		else return -1;
	}
}
int check(int x)
{
	while(sta.size())sta.pop();
	memset(book,0,sizeof book);
	for(int i=1;i<=n;i++)
	{
		if(z[i].a==1){
			if(book[z[i].b]==1)return -1;
			sta.push(z[i].b);
			book[z[i].b]=1;
		}
		else {
			if(sta.size()==0)return -1;
			book[sta.top()]=0;
			sta.pop();
		}
	}
	if(sta.size())return -1;
	for(int i=0;i<=n+1;i++)
	{
		if(z[i].a==1)st.push(make_pair(i,0));
		else{
			if(z[st.top().first].t==-1)st.top().second=0;
			else if(z[st.top().first].t==1)st.top().second++;
			else ;
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
	//freopen("complexity.in","r",stdin);
	//freopen("complexity.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		char s[15];
		scanf("%d %s",&n,s);
		int t=query(s);
		for(int i=1;i<=n;i++)
		{
			char a,b,c[15],d[15];
			scanf(" %c",&a);
			if(a=='F'){
				
				scanf(" %c%s%s",&b,c,d);
				z[i].a=1;
				z[i].b=b-'a';
				z[i].t=change(c,d);
			}else{
				z[i].a=-1;
			}
		}
		z[0].a=1,z[0].b=128,z[0].t=0,z[n+1].a=-1;
		t=check(t);
		if(t==1)puts("Yes");
		else if(t==0)puts("No");
		else puts("ERR");
	}
}