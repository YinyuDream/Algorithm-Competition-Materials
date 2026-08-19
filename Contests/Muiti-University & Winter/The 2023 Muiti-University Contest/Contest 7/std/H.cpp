/*
start thinking:
BULB:
result of thinking:

start coding:
AC:
*/
#include<bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldouble;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;
template<class T> bool chmin(T &x, const T &y) {
  return x > y ? (x = y, true) : false;
}
template<class T> bool chmax(T &x, const T &y) {
  return x < y ? (x = y, true) : false;
}
bool Mbe;

#define maxn 100005
int n, q, a[maxn];
struct Node {
  int maxi;
  double area; // 折线与 x 轴围成的面积
  double ans; // 蓄水面积
} dat[262155];

double calc(int u, int l, int r, int fir) {
  if (l + 1 == r) {
    if (fir >= a[r])
      return fir - (a[l] + a[r]) / 2.;
    else
      return .5 * (fir - a[l]) * (fir - a[l]) / (a[r] - a[l]);
  }
  int mid = (l + r) >> 1;
  if (fir < dat[u << 1].maxi)
    return calc(u << 1, l, mid, fir) + dat[u].ans - dat[u << 1].ans;
  else
    return 1. * fir * (mid - l) - dat[u << 1].area + calc(u << 1 | 1, mid, r, fir);
}

void up(int u, int l, int r) {
  int mid = (l + r) >> 1;
  dat[u].maxi = max(dat[u << 1].maxi, dat[u << 1 | 1].maxi);
  dat[u].area = dat[u << 1].area + dat[u << 1 | 1].area;
  dat[u].ans = dat[u << 1].ans + calc(u << 1 | 1, mid, r, dat[u << 1].maxi);
}

void update(int u, int l, int r, int pos) {
  if (l + 1 == r) {
    dat[u].maxi = max(a[l], a[r]);
    dat[u].area = (a[l] + a[r]) / 2.;
    dat[u].ans = calc(u, l, r, a[l]);
  } else {
    int mid = (l + r) >> 1;
    if (pos <= mid)
      update(u << 1, l, mid, pos);
    if (mid <= pos)
      update(u << 1 | 1, mid, r, pos);
    up(u, l, r);
  }
}

int maxi;
double query(int u, int l, int r, int ql, int qr) {
  if (ql <= l && r <= qr) {
    double ret = calc(u, l, r, maxi);
    chmax(maxi, dat[u].maxi);
    return ret;
  }
  int mid = (l + r) >> 1;
  double res = 0;
  if (ql < mid)
    res += query(u << 1, l, mid, ql, qr);
  if (mid < qr)
    res += query(u << 1 | 1, mid, r, ql, qr);
  return res;
}

bool Med;
int main() {
  fprintf(stderr, "%.2fMB\n", (&Mbe - &Med) / 1048576.0);
  scanf("%d%d", &n, &q);
  assert(n >= 2 && n <= 100000 && q >= 1 && q <= 100000); 
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    assert(a[i] >= 1 && a[i] <= (int)1e9);
    update(1, 1, n, i);
  }
  while (q--) {
    int fl, x, y;
    scanf("%d%d%d", &fl, &x, &y);
    if (fl == 1) {
      a[x] = y;
      assert(1 <= x && x <= n && 1 <= y && y <= (int)1e9);
      update(1, 1, n, x);
    } else {
      assert(fl == 2 && 1 <= x && x < y && y <= n);
      maxi = a[x];
      printf("%.12f\n", query(1, 1, n, x, y));
    }
  }
  cerr << "time: " << clock() << "ms" << endl;
  return 0;
}