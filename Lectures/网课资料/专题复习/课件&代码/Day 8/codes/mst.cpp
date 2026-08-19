/*
Author: yww
Language: C++
Mail: weeerrr720@qq.com
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<functional>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<bitset>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
void open(const char *s){
#ifndef ONLINE_JUDGE
    char str[100];sprintf(str,"%s.in",s);freopen(str,"r",stdin);sprintf(str,"%s.out",s);freopen(str,"w",stdout);
#endif
}
void open2(const char *s){
#ifdef DEBUG
    char str[100];sprintf(str,"%s.in",s);freopen(str,"r",stdin);sprintf(str,"%s.out",s);freopen(str,"w",stdout);
#endif
}
template <class T>
int upmin(T &a, const T &b){return (b<a?a=b,1:0);}
template <class T>
int upmax(T &a, const T &b){return (b>a?a=b,1:0);}
namespace io
{
    const int SIZE=(1<<20)+1;
    char ibuf[SIZE],*iS,*iT;
    char obuf[SIZE],*oS=obuf,*oT=oS+SIZE-1;
    int getc()
    {
        (iS==iT?iS=ibuf,iT=ibuf+fread(ibuf,1,SIZE,stdin):0);
        return iS==iT?EOF:*(iS++);
    }
    int f;
    char c;
    template <class T>
    void get(T &x)
    {
        f=1;
        for(c=getc();(c<'0'||c>'9')&&c!='-';c=getc());
        (c=='-'?f=-1,c=getc():0);
        x=0;
        for(;c>='0'&&c<='9';c=getc())
            x=x*10+c-'0';
        x*=f;
    }
    void flush()
    {
        fwrite(obuf,1,oS-obuf,stdout);
        oS=obuf;
    }
    void putc(char x)
    {
        *(oS++)=x;
        if(oS==oT)
            flush();
    }
    int a[55],t;
    template <class T>
    void put(T x)
    {
        if(!x)
            putc('0');
        x<0?putc('-'),x=-x:0;
        while(x)
        {
            a[++t]=x%10;
            x/=10;
        }
        while(t)
            putc(a[t--]+'0');
    }
    void space()
    {
        putc(' ');
    }
    void enter()
    {
        putc('\n');
    }
    struct flusher
    {
        ~flusher()
        {
            flush();
        }
    }
    io_flusher;
}
const int infi=0x3fffffff;
const ll infll=0x3fffffffffffffffll;

const int N = 100010;

int f[N];
int r[N];

int find(int x) {
	return f[x] == x ? x : f[x] = find(f[x]);
}

int merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) {
		return 0;
	}
	if (r[x] < r[y]) {
		f[x] = y;
		r[y] += r[x];
	} else {
		f[y] = x;
		r[x] += r[y];
	}
	return 1;
}

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

int notprime[N];
int prime[N];
int cnt;

void solve1() {
	int n;
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		if (!notprime[i]) {
			prime[++cnt] = i;
		}
		for (int j = 1; j <= cnt && i * prime[j] <= n; j++) {
			notprime[i * prime[j]] = 1;
			if (i % prime[j] == 0) {
				break;
			}
		}
	}
	ll ans = 0;
	for (int i = n; i >= 1; i--) {
		f[i] = i;
		r[i] = 1;
		for (int j = 1; j <= cnt && i * prime[j] <= n; j++) {
			if (merge(i, i * prime[j])) {
				ans += i;
			}
		}
	}
	printf("%lld\n", ans);
}

void solve2() {
	int n;
	scanf("%d", &n);
	ll ans = 0;
	for (int i = 1; i < n; i++) {
		int j;
		for (j = n; gcd(j, i) != 1; j--);
		ans += (ll)i * j;
	}
	printf("%lld\n", ans);
}

int main()
{
	int t;
	scanf("%d", &t);
	if (t == 1) {
		solve1();
	} else {
		solve2();
	}
	return 0;
}
