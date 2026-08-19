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
const int N = 110;
vector<int> g1[N], g2[N];
int h[N];
int f[2][N][N];
int g[N];
int deg[N];
int q[N];
int s[2][N];

int main() {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &h[i]);
	}
	for (int i = 1; i <= m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		if (h[x] > h[y]) {
			g1[x].push_back(y);
			deg[y]++;
		} else {
			g2[x].push_back(y);
		}
		if (h[y] > h[x]) {
			g1[y].push_back(x);
			deg[x]++;
		} else {
			g2[y].push_back(x);
		}
	}
	
	int head = 1, tail = 0;
	for (int i = 1; i <= n; i++) {
		if (deg[i] == 0) {
			q[++tail] = i;
		}
	}
	while (tail >= head) {
		int x = q[head++];
		for (auto v: g1[x]) {
			deg[v]--;
			if (deg[v] == 0) {
				q[++tail] = v;
			}
		}
	}
	
	int t = 0;
	int ts = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			f[t][i][j] = g[j] = -1;
		}
		g[i] = 0;
		for (int j = 1; j <= n; j++) {
			int x = q[j];
			if (g[x] >= 0) {
				s[ts][i] = max(s[ts][i], g[x]);
				for (auto v: g1[x]) {
					g[v] = max(g[v], g[x] + 1);
				}
			}
		}
		for (int j = 1; j <= n; j++) {
			if (g[j] >= 0) {
				for (auto v: g2[j]) {
					f[t][i][v] = max(f[t][i][v], g[j] + 1);
				}
			}
		}
	}
	
	for (; k; k >>= 1) {
		if (k % 2 == 1) {
			ts ^= 1;
			for (int i = 1; i <= n; i++) {
				s[ts][i] = 0;
				for (int j = 1; j <= n; j++) {
					if (f[t][i][j] >= 0) {
						s[ts][i] = max(s[ts][i], s[ts ^ 1][j] + f[t][i][j]);
					}
				}
			}
		}
		t ^= 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				for (int l = 1; l <= n; l++) {
					if (f[t ^ 1][i][l] >= 0 && f[t ^ 1][l][j] >= 0) {
						f[t][i][j] = max(f[t][i][j], f[t ^ 1][i][l] + f[t ^ 1][l][j]);
					}
				}
			}
		}
	}
	
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, s[ts][i]);
	}
	printf("%d\n", ans);
	return 0;
}

//2 1 1
//2 1
//1 2

//ans: 3
