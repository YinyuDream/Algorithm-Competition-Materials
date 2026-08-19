#include <bits/stdc++.h>

using namespace std;

constexpr int maxn = (1 << 19) + 5, p = 998244353, inv_2 = (p + 1) / 2;

int qpow(int a, int b) {
	int ans = 1;
	while (b) {
		if (b & 1)
			ans = (long long)ans * a % p;
		
		b >>= 1;
		a = (long long)a * a % p;
	}
	return ans;
}

vector<int> omega[25];

void NTT_init(int n) {
	for (int k = 2, d = 0; k <= n; k *= 2, d++) {
		omega[d].resize(k + 1);

		int wn = qpow(3, (p - 1) / k), tmp = 1;
		for (int i = 0; i <= k; i++) {
			omega[d][i] = tmp;
			tmp = (long long)tmp * wn % p;
		}
	}
}

void NTT(int *c, int n, int tp) {
	static unsigned long long a[maxn];
	for (int i = 0; i < n; i++)
		a[i] = c[i];

	for (int i = 1, j = 0; i < n - 1; i++) {
		int k = n;
		do
			j ^= (k >>= 1);
		while (j < k);

		if (i < j)
			swap(a[i], a[j]);
	}

	for (int k = 1, d = 0; k < n; k *= 2, d++) {
		if (d == 16)
			for (int i = 0; i < n; i++)
				a[i] %= p;

		for (int i = 0; i < n; i += k * 2)
			for (int j = 0; j < k; j++) {
				int w = omega[d][tp > 0 ? j : k * 2 - j];
				unsigned long long u = a[i + j],
					v = w * a[i + j + k] % p;
				a[i + j] = u + v;
				a[i + j + k] = u - v + p;
			}
		}
		
	if (tp > 0) {
		for (int i = 0; i < n; i++)
			c[i] = a[i] % p;
	}
	else {
		int inv = qpow(n, p - 2);
		for (int i = 0; i < n; i++)
			c[i] = a[i] * inv % p;
	}
}

void get_inv(int *A, int *C, int n) {
	static int B[maxn];

	memset(C, 0, sizeof(int) * (n * 2));
	C[0] = 1;

	for (int k = 2; k <= n; k *= 2) {
		memcpy(B, A, sizeof(int) * k);
		memset(B + k, 0, sizeof(int) * k);

		NTT(B, k * 2, 1);
		NTT(C, k * 2, 1);
		
		for (int i = 0; i < k * 2; i++) {
			C[i] = (2 - (long long)B[i] * C[i]) % p * C[i] % p;
			if (C[i] < 0)
				C[i] += p;
		}
		
		NTT(C, k * 2, -1);

		memset(C + k, 0, sizeof(int) * k);
	}
}

int fac[maxn], fac_inv[maxn];

int ch[maxn], sh[maxn], a[maxn], b[maxn], c[maxn];

int main() {
	ios::sync_with_stdio(false);

	int n, x;
	cin >> n >> x;

	if (n == 0) {
		cout << x << endl;
		return 0;
	}
	
	int N = 1;
	while (N <= n)
		N *= 2;

	NTT_init(N * 2);

	fac[0] = fac_inv[0] = 1;
	for (int i = 1; i <= n; i++)
		fac[i] = (long long)i * fac[i - 1] % p;
	fac_inv[n] = qpow(fac[n], p - 2);
	for (int i = n - 1; i; i--)
		fac_inv[i] = (long long)(i + 1) * fac_inv[i + 1] % p;
	
	for (int i = 0; i <= n; i++) {
		(i & 1 ? sh : ch)[i] = fac_inv[i];

		a[i] = ((long long)x * ch[i] - sh[i]) % p;
		if (a[i] < 0)
			a[i] += p;
		
		b[i] = (ch[i] - (long long)x * sh[i]) % p;
		if (b[i] < 0)
			b[i] += p;
	}

	get_inv(b, c, N);

	NTT(a, N * 2, 1);
	NTT(c, N * 2, 1);

	for (int i = 0; i < N * 2; i++)
		a[i] = (long long)a[i] * c[i] % p;
	
	NTT(a, N * 2, -1);

	cout << (long long) a[n] * fac[n] % p << endl;

	return 0;
}
