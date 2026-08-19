#include "iostream"
#include "algorithm"
#include "cstring"
#include "cstdio"
#include "cmath"
#include "vector"
#include "map"
#include "set"
#include "queue"
#include "numeric"
using namespace std;
#define MAXN 300006
//#define int long long
#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define vi vector<int>
#define all(x) (x).begin() , (x).end()
#define mem( a ) memset( a , 0 , sizeof a )
typedef long long ll;
#define P 998244353
int n , q;
const int mxv = 500;
int V[MAXN] , W[MAXN];
int dp[MAXN][506] , wy[MAXN][506] , nd[MAXN] , dep[MAXN << 2]; pii ans[MAXN];

struct tcc {
	int l , r , x , dx;
};

vector<tcc> qs[20006 << 2];
void build( int rt , int l , int r , int d ) {
	dep[rt] = d;
	if( l == r ) { nd[l] = rt; return; }
	int m = l + r >> 1;
	build( rt << 1 , l , m , d + 1 ) , build( rt << 1 | 1 , m + 1 , r , d + 1 );
}
void sol( int rt , int l , int r ) {
	if( l == r ) {
		for( auto [l , r , x , dx] : qs[rt] ) 
			if( x >= V[l] ) ans[dx] = mp( W[l] , 1 );
		return;
	}
	int m = l + r >> 1;
	sol( rt << 1 , l , m ) , sol( rt << 1 | 1 , m + 1 , r );
	dp[m][0] = dp[m + 1][0] = 0 , wy[m][0] = wy[m + 1][0] = 1;
	rep( i , 1 , mxv ) dp[m][i] = dp[m + 1][i] = -0x3f3f3f3f , wy[m][i] = wy[m + 1][i] = 0;
	per( i , m , l ) {
		if( i != m ) rep( j , 0 , mxv ) dp[i][j] = dp[i + 1][j] , wy[i][j] = wy[i + 1][j];
		int *d = dp[i] , *w = wy[i];
		per( v , mxv , V[i] ) {
			if( d[v] < d[v - V[i]] + W[i] ) d[v] = d[v - V[i]] + W[i] , w[v] = w[v - V[i]];
			else if( d[v] == d[v - V[i]] + W[i] ) w[v] = ( w[v] + w[v - V[i]] ) % P;
		}
	}
	per( i , m , l ) {
		int *d = dp[i] , *w = wy[i];
		rep( i , 1 , mxv ) {
			if( d[i] < d[i - 1] ) w[i] = w[i - 1] , d[i] = d[i - 1];
			else if( d[i] == d[i - 1] ) ( w[i] += w[i - 1] ) %= P;
		}
	}
	rep( i , m + 1 , r ) {
		if( i != m + 1 ) rep( j , 0 , mxv ) dp[i][j] = dp[i - 1][j] , wy[i][j] = wy[i - 1][j];
		int *d = dp[i] , *w = wy[i];
		per( v , mxv , V[i] ) {
			if( d[v] < d[v - V[i]] + W[i] ) d[v] = d[v - V[i]] + W[i] , w[v] = w[v - V[i]];
			else if( d[v] == d[v - V[i]] + W[i] ) ( w[v] += w[v - V[i]] ) %= P;
		}
	}
	
	for( auto [l , r , x , dx] : qs[rt] ) {
		int mx = 0 , s = 0;
		rep( k , 0 , x ) {
			if( dp[r][k] + dp[l][x - k] > mx ) mx = dp[r][k] + dp[l][x - k] , s = wy[r][k] * 1ll * wy[l][x - k] % P;
			else if( dp[r][k] + dp[l][x - k] == mx ) s += wy[r][k] * 1ll * wy[l][x - k] % P , s %= P;
		}
		ans[dx] = mp( mx , s );
	}
	
}

void solve() {
	cin >> n;
	rep( i , 1 , n ) scanf("%d%d",W + i,V + i);
	build( 1 , 1 , n , 1 );
	cin >> q;
	rep( i , 1 , q ) {
		static int l , r , m , L , R;
		scanf("%d%d%d",&l,&r,&m);
		L = nd[l] , R = nd[r];
		if( dep[L] > dep[R] ) L >>= 1;
		if( dep[R] > dep[L] ) R >>= 1;
		while( L != R ) L >>= 1 , R >>= 1;
		qs[L].eb( (tcc) { l , r , m , i } );
	}
	sol( 1 , 1 , n );
	rep( i , 1 , q ) {
		if( ans[i].fi == 0 ) ans[i].se = 0;
		printf("%d %d\n",ans[i].fi,ans[i].se);
	}
}

signed main() {
//	freopen("ex_knapsack4.in","r",stdin);
//	freopen("ot","w",stdout);
//    int T;cin >> T;while( T-- ) solve();
    solve();
}