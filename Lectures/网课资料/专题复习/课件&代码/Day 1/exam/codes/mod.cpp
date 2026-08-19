
#include <cstdio>
#include <cstring>

using namespace std;

const int Max_N(10000000);
typedef long long int LL;

bool Prime[Max_N + 5];
int ps, P[Max_N + 5];
LL mp1[Max_N + 5], d1[Max_N + 5], d1o[Max_N + 5], Pred1[Max_N + 5];

namespace io {
	const int SIZE = (1 << 21) + 1;
	char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c, qu[55]; int f, qr;
	// getchar
	#define gc() (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++)
	// print the remaining part
	inline void flush () {
		fwrite (obuf, 1, oS - obuf, stdout);
		oS = obuf;
	}
	// putchar
	inline void putc (char x) {
		*oS ++ = x;
		if (oS == oT) flush ();
	}
	// input a signed integer
	template <class I>
	inline void gi (I &x) {
		for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;
		for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f;
	}
	// print a signed integer
	template <class I>
	inline void print (I x) {
		if (!x) putc ('0'); if (x < 0) putc ('-'), x = -x;
		while (x) qu[++ qr] = x % 10 + '0',  x /= 10;
		while (qr) putc (qu[qr --]);
	}
	//no need to call flush at the end manually!
	struct Flusher_ {~Flusher_(){flush();}}io_flusher_;
}
using io :: gi;
using io :: putc;
using io :: print;

int main()
{
	memset(Prime, true, sizeof(Prime)), Prime[0] = Prime[1] = false;
	mp1[1] = d1[1] = d1o[1] = 1LL;
	for (int i = 2;i <= Max_N;++i)
	{
		if (Prime[i])
		{
			P[++ps] = i;
			mp1[i] = i * 1LL, d1[i] = 1 + i * 1LL, d1o[i] = 1LL;
		}
		for (int j = 1, x;j <= ps && i * P[j] <= Max_N;++j)
		{
			Prime[x = i * P[j]] = false;
			if (i % P[j])
			{
				mp1[x] = P[j];
				d1[x] = d1[i] * d1[P[j]], d1o[x] = d1[i];
			}
			else
			{
				mp1[x] = mp1[i] * P[j];
				d1[x] = d1[i] + d1o[i] * mp1[x], d1o[x] = d1o[i];
				break;
			}
		}
	}
	for (int i = 1;i <= Max_N;++i)
		Pred1[i] = Pred1[i - 1] + d1[i];
	int T, N;
	gi(T);
	while (T--)
		gi(N), print((N * 1LL) * (N * 1LL) - Pred1[N]), putc('\n');;
	return 0;
}
