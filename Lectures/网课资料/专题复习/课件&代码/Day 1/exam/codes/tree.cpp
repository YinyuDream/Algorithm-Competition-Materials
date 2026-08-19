
#include <cstdio>

using namespace std;
const int MOD(1000000000 + 7);
const int Max_N(1000050);

namespace io
{
	const int SIZE = (1 << 21) + 1;
	char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c, qu[55]; int f, qr;
	#define gc() (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++)
	inline void flush (){fwrite (obuf, 1, oS - obuf, stdout);oS = obuf;}
	inline void putc (char x){*oS ++ = x;if (oS == oT) flush ();}
	template <class I>
	inline void gi (I &x) {for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;
		for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f;}
	template <class I>
	inline void print (I x){
		if (!x) putc ('0'); if (x < 0) putc ('-'), x = -x;while(x) qu[++ qr] = x % 10 + '0',  x /= 10;while (qr) putc (qu[qr--]);}
	struct Flusher_ {~Flusher_(){flush();}}io_flusher_;
}
using io::gi;
using io::putc;
using io::print;

constexpr int Add(int a, int b)
{
	return a + b >= MOD ? a + b - MOD : a + b;
}

constexpr int Mult(int a, int b)
{
	return a * 1LL * b % MOD;
}

void exgcd(int a, int b, int &x, int &y)
{
	if (b == 0)
		x = 1, y = 0;
	else
		exgcd(b, a % b, y, x), y -= x * (a / b);
}

inline int inverse(int a)
{
	int invx, invy;
	exgcd(a, MOD, invx, invy);
	return (invx % MOD + MOD) % MOD;
}

int N, Head[Max_N], Next[Max_N], Size[Max_N], Fac[Max_N], Inv[Max_N], Ans;

inline void Add_Edge(int s, int t)
{
	Next[t] = Head[s], Head[s] = t;
}

void dfs(int u)
{
	Size[u] = 1;
	for (int v = Head[u];v;v = Next[v])
		dfs(v), Size[u] += Size[v];
	Ans = Add(Ans, Mult(Inv[Size[u]], Fac[Size[u] - 1]));
}

int main()
{
	gi(N);
	for (int u = 2, fa;u <= N;++u)
		gi(fa), Add_Edge(fa, u);
	Fac[0] = 1;
	for (int i = 1;i <= N;++i)
		Fac[i] = Mult(Fac[i - 1], i);
	Inv[N] = inverse(Fac[N]);
	for (int i = N - 1;i >= 0;--i)
		Inv[i] = Mult(Inv[i + 1], i + 1);
	dfs(1);
	print(Ans);
	return 0;
}
