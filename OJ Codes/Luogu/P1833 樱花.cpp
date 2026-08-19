#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=1e5+10;
int t[maxn],c[maxn],p[maxn],dp[maxn*30];
int w[maxn],q[maxn];
int ts1,ts2,te1,te2,n,cnt;
//vector<int>test;
void pre_work()
{
	for(int i=1;i<=n;i++)
	{		
//	printf("%d:",i);
 	 		int k=0,sum=0;
 	 		while(sum+(1<<k)<=p[i])
 	 		{
 	 			//test.push_back(1<<k);
 	 			sum+=1<<k;
 	 			w[++cnt]=t[i]*(1<<k);
 	 			q[cnt]=c[i]*(1<<k);
 	 			k++;
	        }
 	 		if(p[i]-sum>0)
 	 		w[++cnt]=t[i]*(p[i]-sum),
 	 		q[cnt]=c[i]*(p[i]-sum);
 	 	//	test.push_back(p[i]-sum);
			//for(int i=0;i<test.size();i++)
			//printf("%d   ",test[i]);
			//puts("");
		//	test.clear();
	}
}
int main(){
	scanf("%d:%d %d:%d %d",&ts1,&ts2,&te1,&te2,&n);
	int ti=te1*60+te2-ts1*60-ts2;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&t[i],&c[i],&p[i]);
		if(p[i]==0)
		p[i]=ti/t[i];
	}
	//for(int i=1;i<=n;i++)
	//printf("%d   ",1<<5);
	pre_work();
	//for(int i=1;i<=cnt;i++)
	//printf("%d   %d   %d\n",i,w[i],t[i]);
	for(int i=1;i<=cnt;i++)
			for(int j=ti;j>=1;j--)
					if(j-w[i]>=0)
					dp[j]=max(dp[j],dp[j-w[i]]+q[i]);
	printf("%d",dp[ti]);
	return 0;
}
