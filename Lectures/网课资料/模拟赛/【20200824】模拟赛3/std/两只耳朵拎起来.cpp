#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<algorithm>

using namespace std;

const int BUF_SIZE = 30;
char buf[BUF_SIZE], *buf_s = buf, *buf_t = buf + 1;
  
#define PTR_NEXT() \
    { \
        buf_s ++; \
        if (buf_s == buf_t) \
        { \
            buf_s = buf; \
            buf_t = buf + fread(buf, 1, BUF_SIZE, stdin); \
        } \
    }
   
#define readint(_n_) \
    { \
        while (*buf_s != '-' && !isdigit(*buf_s)) \
            PTR_NEXT(); \
        bool register _nega_ = false; \
        if (*buf_s == '-') \
        { \
            _nega_ = true; \
            PTR_NEXT(); \
        } \
        int register _x_ = 0; \
        while (isdigit(*buf_s)) \
        { \
            _x_ = _x_ * 10 + *buf_s - '0'; \
            PTR_NEXT(); \
        } \
        if (_nega_) \
            _x_ = -_x_; \
        (_n_) = (_x_); \
    }

#define inc(a,b) {a+=b;if (a>=mo) a-=mo;}
#define dec(a,b) {a-=b;if (a<0) a+=mo;}

const int maxn=100010;
const int maxm=200010;
const int mo=1000000007;

int n,m,k,en,deg[maxn],edx[maxm][2],col[maxn],z[maxn];

struct edge
{
	int e;
	edge *next;
}*v[maxn],ed[maxm];

void add_edge(int s,int e,int x=0)
{
	en++;
	ed[en].next=v[s];v[s]=ed+en;v[s]->e=e;
	if (!x) deg[s]++;
}

int mul(int a,int b)
{
	if (b<0) return 0;
	int ans=1;
	while (b)
	{
		if (b&1) ans=1ll*ans*a%mo;
		a=1ll*a*a%mo;
		b>>=1;
	}
	return ans;
}	

bool cmp(int p1,int p2)
{
	return deg[p1]>deg[p2] || (deg[p1]==deg[p2] && p1<p2);
}

int main()
{
	int test=1;
	for (;test--;)
	{
		memset(deg,0,sizeof(deg));
		en=0;
		memset(v,0,sizeof(v));
		readint(n);
		readint(m);
		readint(k);
		for (int a=1;a<=m;a++)
		{
			int s,e;
			readint(s);
			readint(e)
				add_edge(s,e);
			add_edge(e,s);
			edx[a][0]=s;edx[a][1]=e;
		}
		int ans=0;
		if (k==1) {if (n>=2) ans=1ll*m*mul(2,n-2)%mo;}
		else if (k==2)
		{
			if (n>=2) ans=1ll*m*mul(2,n-2)%mo;
			int line=0;
			for (int a=1;a<=n;a++)
				inc(line,1ll*deg[a]*(deg[a]-1)/2%mo);
			if (n>=3) inc(ans,1ll*line*mul(2,n-2)%mo);
			int two_line=1ll*m*(m-1)/2%mo;
			dec(two_line,line);
			if (n>=4) inc(ans,1ll*two_line*mul(2,n-3)%mo);
		}
		else
		{
			{
				if (n>=2) ans=1ll*m*mul(2,n-2)%mo;
				int line=0;
				for (int a=1;a<=n;a++)
					inc(line,1ll*deg[a]*(deg[a]-1)/2%mo);
				if (n>=3) inc(ans,1ll*line*mul(2,n-2)%mo*3%mo);
				int two_line=m*(m-1)/2%mo;
				dec(two_line,line);
				if (n>=4) inc(ans,1ll*two_line*mul(2,n-3)%mo*3%mo);
			}

			for (int a=1;a<=n;a++)
				z[a]=a;
			sort(z+1,z+n+1,cmp);
			en=0;
			memset(v,0,sizeof(v));
			for (int a=1;a<=m;a++)
				if (cmp(edx[a][0],edx[a][1])) add_edge(edx[a][0],edx[a][1],1);
				else add_edge(edx[a][1],edx[a][0],1);

			int triple=0;
			memset(col,0,sizeof(col));
			for (int a=1;a<=n;a++)
			{
				int p1=z[a];
				for (edge *e=v[p1];e;e=e->next)
					col[e->e]=p1;
				for (edge *e=v[p1];e;e=e->next)
					for (edge *ee=v[e->e];ee;ee=ee->next)
						if (col[ee->e]==p1) triple++;
			}
			if (n>=4) inc(ans,1ll*triple*mul(2,n-3)%mo*6%mo);

			int line=0;
			for (int a=1;a<=m;a++)
			{
				int p1=edx[a][0],p2=edx[a][1];
				inc(line,1ll*(deg[p1]-1)*(deg[p2]-1)%mo);
			}
			dec(line,triple);
			dec(line,triple);
			dec(line,triple);
			if (n>=4) inc(ans,1ll*line*mul(2,n-4)%mo*6%mo);


			int central=0;
			for (int a=1;a<=n;a++)
			{
				inc(central,1ll*deg[a]*(deg[a]-1)*(deg[a]-2)/6%mo);
			}
			if (n>=4) inc(ans,1ll*central*mul(2,n-4)%mo*6%mo);

			int two_line=0;
			for (int a=1;a<=n;a++)
				inc(two_line,1ll*deg[a]*(deg[a]-1)/2*(m-deg[a])%mo);
			dec(two_line,triple);
			dec(two_line,triple);
			dec(two_line,triple);
			dec(two_line,line);
			dec(two_line,line);
			inc(ans,1ll*two_line*mul(2,n-5)%mo*6%mo);


			int three_line = 1ll*m*(m-1)*(m-2)/6%mo;
			dec(three_line,triple);
			dec(three_line,line);
			dec(three_line,central);
			dec(three_line,two_line);
			if (n>=6) inc(ans,1ll*three_line*mul(2,n-6)%mo*6%mo);


			//printf("%d\n",triple);
			//printf("%d\n",line);
			//printf("%d\n",central);
			//printf("%d\n",two_line);
			//printf("%d\n",three_line);

		}
		printf("%d\n",ans);
	}

	return 0;
}
