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
#define MAXN 800006
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
const int P = 998244353;
ll n , k , a , b;

int Pow( int x , int a ) {
	int ret = 1;
	while( a ) {
		if( a & 1 ) ret = ret * 1ll * x % P;
		x = x * 1ll * x % P , a >>= 1;
	}
	return ret;
}

int rev[MAXN] , Wn[2][MAXN];
void getwn( int len ) {
	for( int mid = 1 ; mid < len ; mid <<= 1 ) {
		int w0 = Pow( 3 , ( P - 1 ) / ( mid << 1 ) ) , w1 = Pow( 3 , P - 1 - ( P - 1 ) / ( mid << 1 ) );
		Wn[0][mid] = Wn[1][mid] = 1;
		rep( i , 1 , mid - 1 ) 
			Wn[0][mid + i] = Wn[0][mid + i - 1] * 1ll * w0 % P,
			Wn[1][mid + i] = Wn[1][mid + i - 1] * 1ll * w1 % P;
	}
}
void getr( int len ) {
	int l = __builtin_ctz( len ) - 1;
	rep( i , 1 , len - 1 ) rev[i] = ( rev[i >> 1] >> 1 ) | ( ( i & 1 ) << l );
}
void NTT( int A[] , int len , int typ ) {
	rep( i , 0 , len - 1 ) if( i < rev[i] ) swap( A[i] , A[rev[i]] );
	for( int mid = 1 ; mid < len ; mid <<= 1 ) 
		for( int i = 0 ; i < len ; i += ( mid << 1 ) )
			for( int j = i ; j < i + mid ; ++ j ) {
				int t0 = A[j] , t1 = A[j + mid] * 1ll * Wn[typ][j - i + mid] % P;
				A[j] = ( t0 + t1 > P ? t0 + t1 - P : t0 + t1 ) , A[j + mid] = ( t0 < t1 ? t0 + P - t1 : t0 - t1 );
			}
	if( typ ) for( int i = 0 , iv = Pow( len , P - 2 ) ; i < len ; ++ i ) A[i] = A[i] * 1ll * iv % P;
}

int A[MAXN];
void sol( ll n ) {
	if( n == 1 ) { A[0] = A[1] = 1; return; }
	sol( n >> 1 );
	int len = 1; while( len <= k + k ) len <<= 1; 
	getr( len );
	NTT( A , len , 0 ); rep( i , 0 , len - 1 ) A[i] = A[i] * 1ll * A[i] % P; NTT( A , len , 1 );
	if( n & 1 ) 
		per( i , len , 1 ) A[i] = ( A[i] + A[i - 1] ) % P;
	rep( i , k , len ) A[i - k] = ( A[i - k] + A[i] * 1ll * a ) % P , A[i] = 0;
}

void solve() {
	getwn( 1 << 18 );
	cin >> n >> k >> a >> b;
	a = a * 1ll * Pow( b % P , k ) % P;
	if( k == 1 ) return printf("%d\n",Pow( a % P + 1 , n % ( P - 1 ) )) , void();
	ll t = n * 1ll * k;
	sol( t );
	cout << A[0] << endl;
}

signed main() {
//    int T;cin >> T;while( T-- ) solve();
    solve();
}