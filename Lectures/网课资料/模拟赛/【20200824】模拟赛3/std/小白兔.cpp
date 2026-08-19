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

#define wmt 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

const int maxn=100010;

int n,m,maxv[maxn<<2|1],lsum[maxn<<2|1],rsum[maxn<<2|1];

int query_max(int l,int r,int rt,int nowl,int nowr)
{
	if (nowl<=l && r<=nowr) return maxv[rt];
	int m=(l+r)>>1;
	if (nowl<=m)
	{
		if (m<nowr) return max(query_max(lson,nowl,nowr),query_max(rson,nowl,nowr));
		else return query_max(lson,nowl,nowr);
	}
	else return query_max(rson,nowl,nowr);
}

int query_lsum(int l,int r,int rt,int nowl,int nowr)
{
	if (nowl<=l && r<=nowr) return lsum[rt];
	int m=(l+r)>>1;
	if (nowl<=m)
	{
		if (m<nowr) return query_lsum(lson,nowl,nowr)+query_lsum(rson,nowl,nowr);
		else return query_lsum(lson,nowl,nowr);
	}
	else return query_lsum(rson,nowl,nowr);
}

int query_rsum(int l,int r,int rt,int nowl,int nowr)
{
	if (nowl<=l && r<=nowr) return rsum[rt];
	int m=(l+r)>>1;
	if (nowl<=m)
	{
		if (m<nowr) return query_rsum(lson,nowl,nowr)+query_rsum(rson,nowl,nowr);
		else return query_rsum(lson,nowl,nowr);
	}
	else return query_rsum(rson,nowl,nowr);
}

int query_l(int l,int r,int rt,int nowl,int nowr,int &v)
{
	int m=(l+r)>>1;
	if (nowl<=l && r<=nowr)
	{
		if (l==r)
		{
			if (v>=maxv[rt]) return 0;
			else
			{
				v=maxv[rt];
				return 1;
			}
		}
		int l_max = query_max(lson,nowl,nowr);
		if (v >= l_max)
		{
			int ans=query_l(rson,nowl,nowr,v);
			v=max(v,maxv[rt]);
			return ans;
		}
		else
		{
			int ans=query_l(lson,nowl,nowr,v)+lsum[rt]-lsum[rt<<1];
			v=max(v,maxv[rt]);
			return ans;
		}
	}
	int ans=0;
	if (nowl<=m) ans+=query_l(lson,nowl,nowr,v);
	if (m<nowr) ans+=query_l(rson,nowl,nowr,v);
	return ans;
}

int query_r(int l,int r,int rt,int nowl,int nowr,int &v)
{
	int m=(l+r)>>1;
	if (nowl<=l && r<=nowr)
	{
		if (l==r)
		{
			if (v>=maxv[rt]) return 0;
			else
			{
				v=maxv[rt];
				return 1;
			}
		}
		int r_max = query_max(rson,nowl,nowr);
		if (v >= r_max)
		{
			int ans=query_r(lson,nowl,nowr,v);
			v=max(v,maxv[rt]);
			return ans;
		}
		else
		{
			int ans=query_r(rson,nowl,nowr,v)+rsum[rt]-rsum[rt<<1|1];
			v=max(v,maxv[rt]);
			return ans;
		}
	}
	int ans=0;
	if (m<nowr) ans+=query_r(rson,nowl,nowr,v);
	if (nowl<=m) ans+=query_r(lson,nowl,nowr,v);
	return ans;
}


void update(int l,int r,int rt)
{
	int m=(l+r)>>1;
	maxv[rt]=max(maxv[rt<<1],maxv[rt<<1|1]);
	int v=maxv[rt<<1];
	lsum[rt]=lsum[rt<<1] + query_l(rson,m+1,r,v);
	v=maxv[rt<<1|1];
	rsum[rt]=rsum[rt<<1|1] + query_r(lson,l,m,v);
}

void build(int l,int r,int rt)
{
	if (l==r)
	{
		readint(maxv[rt]);
		lsum[rt]=rsum[rt]=1;
		return;
	}
	int m=(l+r)>>1;
	build(lson);
	build(rson);
	update(l,r,rt);
}

void modify(int l,int r,int rt,int p,int v)
{
	if (l==r)
	{
		maxv[rt]=v;
		return;
	}
	int m=(l+r)>>1;
	if (p<=m) modify(lson,p,v);
	else modify(rson,p,v);
	update(l,r,rt);
}

int main()
{
	readint(n);
	readint(m);
	build(wmt);
	for (int a=1;a<=m;a++)
	{
		int opt;
		readint(opt);
		if (opt==1)
		{
			int p,v;
			readint(p);
			readint(v);
			modify(wmt,p,v);
		}
		else
		{
			int p;
			int v1=-1,v2=-1;
			readint(p);
			int ans=0;
			if (p!=1) ans+=query_r(wmt,1,p-1,v1);
			if (p!=n) ans+=query_l(wmt,p+1,n,v2);
			printf("%d\n",ans+1);
		}
	}

	return 0;
}
