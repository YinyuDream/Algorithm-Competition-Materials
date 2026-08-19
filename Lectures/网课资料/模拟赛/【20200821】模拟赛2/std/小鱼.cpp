#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
#include<set>
#include<map>
#include<cstdlib>
#include<bitset>
#include<stack>
#include<ctime>
#include<fstream>
#define dd double
#define ll long long
#define mp make_pair
#define pb push_back
#define N 10000010
#define M 1010
using namespace std;
int T,n;
int cnt,pri[N];
bool f[N];
//��x���������ֽ�Ϊa1^b1*a2^b2*��*an^bn,����a1����С������
//��g[x]=w[a1^b1],w[x]��ʾ��,last[i]=a1^b1
ll g[N],w[N];
int last[N];
int main()
{
	w[1]=1;
	for(int i=2;i<N;i++)
	{
		if(!f[i])
		{
			pri[++cnt]=last[i]=i;
			g[i]=w[i]=(ll)i*(i-1)+1;
		}
		for(int j=1;i*pri[j]<N;j++)
		{
			int x=pri[j],y=i*x;
			f[y]=true;
			if(!(i%x))
			{
				g[y]=g[i]*x*x-x+1;
				w[y]=w[i/last[i]]*g[y];
				last[y]=last[i]*x;
				break;
			}
			g[y]=(ll)x*(x-1)+1;
			w[y]=w[i]*w[x];
			last[y]=x;
		}
	}
	cin>>T;
	while(T--)
	{
		scanf("%d",&n);
		printf("%lld\n",w[n]);
	}
}