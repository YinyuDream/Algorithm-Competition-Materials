/*
给出n(n≤15)个字符串，求一个最短的串S，使得给出的那些串都是S的子串。
如果有多个解输出字典序最小的一个。
http://acm.pku.edu.cn/JudgeOnline/problem?id=1795
*/
/*
Sol :SCDP
Time:O(n^2*2^n)
Spc :O(n*2^n)
*/
#include<iostream>
using namespace std;
const int mn=15,ms=1<<15,ml=100+2,inf=1<<30;

int n,test,idx[mn],d[mn+1][mn],f[mn][ms],p[mn+1]={1},e[ms+1],l[mn];
char s[mn][ml];

int main()
{
	scanf("%d",&test);
	for(int i=1;i<=mn;i++)p[i]=p[i-1]*2,e[p[i]]=i;
	for(int tn=1;tn<=test;tn++)
	{
		scanf("%d",&n);
		for(int i=0;i<n;idx[i]=i,i++)scanf("%s",s[i]);
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(i!=j&&strstr(s[idx[j]],s[idx[i]])){idx[i--]=idx[n--];break;}
		for(int i=0;i<n;l[i]=strlen(s[idx[i]]),i++);
		for(int i=0,ml;i<n;i++)
			for(int j=0;j<n;j++)
				{
					d[i][j]=0,ml=min(l[i],l[j]);
					for(int p=l[i]-ml;p<l[i];p++)
						if(strstr(s[idx[j]],s[idx[i]]+p)==s[idx[j]]){d[i][j]=l[i]-p; break;}
				}
		
		for(int i=1,j;i<p[n];i++)
			for(int ti=i,t1,p1;ti;ti^=t1)
			{
				t1=ti&-ti, j=i^t1, p1=e[t1];
				f[p1][i]=(t1==i?l[p1]:inf);
				for(int tj=j,t2,p2;tj;tj^=t2)
				{
					t2=tj&-tj, p2=e[t2];
					f[p1][i]<?=f[p2][j]+l[p1]-d[p1][p2];
				}
			}
			
		printf("Scenario #%d:\n",tn);
		for(int ml,mp,ts,tmp,tp,tl,lp=15,st=p[n]-1;st;lp=mp,st^=p[mp])
		{
			char *mstr;
			for(ml=inf,ts=st;ts;ts^=tmp)
			{
				tmp=ts&-ts,tp=e[tmp],tl=f[tp][st]-d[lp][tp];
				char *tstr=s[idx[tp]]+d[lp][tp];
				if(tl<ml||tl==ml&&strcmp(tstr,mstr)<0)
					ml=tl,mp=tp,mstr=tstr;
			}
			printf("%s",mstr);
		}
		printf("\n\n");
	}
	return 0;
}
