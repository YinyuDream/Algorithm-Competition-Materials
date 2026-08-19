#include<cstdio>
#include<cstdlib>
#include<cstring>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>

using namespace std;

const int mn = 251;
const long long INF=0x3f3f3f3f3f3f3f3fll;

int n,w,x[3][mn],y[3][mn];

long long f[mn][mn][mn],z[3][mn];

void parse(vector<string> arr,int w)
{
	string s="";
	for (int a=0;a<arr.size();a++)
		s=s+arr[a];
	stringstream reader;
	reader << s;
	int x;
	n=0;
	while (reader >> x)
		z[w][++n] = x;
}

bool cmp(int a,int b)
{
	return z[w][a]<z[w][b];
}

long long work()
{
	for (w=0;w<3;w++)
	{
		for (int a=1;a<=n;a++)
			y[w][a]=a;
		sort(y[w]+1,y[w]+n+1,cmp);
		for (int a=1;a<=n;a++)
			x[w][y[w][a]]=a;
	}
	memset(f,0x3f,sizeof(f));
	f[0][0][0]=0;
	for (int a=0;a<=n;a++)
		for (int b=0;b<=n;b++)
			for (int c=0;c<=n;c++)
				if (f[a][b][c]!=INF)
				{
					if (a!=n)
					{
						int p = y[0][a+1];
						if (x[1][p] <= b && x[2][p]<=c) f[a+1][b][c]=min(f[a+1][b][c],f[a][b][c]+z[1][y[1][b]]+z[2][y[2][c]]-z[1][p]-z[2][p]);
						else f[a+1][b][c] = min(f[a+1][b][c],f[a][b][c]);
					}
					if (b!=n)
					{
						int p = y[1][b+1];
						if (x[0][p] <= a && x[2][p]<=c) f[a][b+1][c]=min(f[a][b+1][c],f[a][b][c]+z[0][y[0][a]]+z[2][y[2][c]]-z[0][p]-z[2][p]);
						else f[a][b+1][c] = min(f[a][b+1][c],f[a][b][c]);
					}
					if (c!=n)
					{
						int p = y[2][c+1];
						if (x[0][p] <= a && x[1][p]<=b) f[a][b][c+1]=min(f[a][b][c+1],f[a][b][c]+z[0][y[0][a]]+z[1][y[1][b]]-z[0][p]-z[1][p]);
						else f[a][b][c+1] = min(f[a][b][c+1],f[a][b][c]);
					}
				}
	return f[n][n][n];
}

int main()
{
	scanf("%d",&n);
	for (int a=1;a<=n;a++)
		for (int b=0;b<3;b++)
			scanf("%lld",&z[b][a]);
	printf("%lld\n",work());

	return 0;
}

/*
class SlimeXSlimeRancher {
	public:
		long long train(vector <string> first_slime, vector <string> second_slime, vector <string> third_slime) {
			parse(first_slime,0);
			parse(second_slime,1);
			parse(third_slime,2);
			return work();
		}
};

vector<string> split( const string& s, const string& delim =" " ) {
	vector<string> res;
	string t;
	for ( int i = 0 ; i != s.size() ; i++ ) {
		if ( delim.find( s[i] ) != string::npos ) {
			if ( !t.empty() ) {
				res.push_back( t );
				t = "";
			}
		} else {
			t += s[i];
		}
	}
	if ( !t.empty() ) {
		res.push_back(t);
	}
	return res;
}

vector<int> splitInt( const string& s, const string& delim =" " ) {
	vector<string> tok = split( s, delim );
	vector<int> res;
	for ( int i = 0 ; i != tok.size(); i++ )
		res.push_back( atoi( tok[i].c_str() ) );
	return res;
}

// BEGIN CUT HERE
#define ARRSIZE(x) (sizeof(x)/sizeof(x[0]))

template<typename T> void print( T a ) {
	cerr << a;
}
static void print( long long a ) {
	cerr << a << "L";
}
static void print( string a ) {
	cerr << '"' << a << '"';
}
template<typename T> void print( vector<T> a ) {
	cerr << "{";
	for ( int i = 0 ; i != a.size() ; i++ ) {
		if ( i != 0 ) cerr << ", ";
		print( a[i] );
	}
	cerr << "}" << endl;
}
template<typename T> void eq( int n, T have, T need ) {
	if ( have == need ) {
		cerr << "Case " << n << " passed." << endl;
	} else {
		cerr << "Case " << n << " failed: expected ";
		print( need );
		cerr << " received ";
		print( have );
		cerr << "." << endl;
	}
}
template<typename T> void eq( int n, vector<T> have, vector<T> need ) {
	if( have.size() != need.size() ) {
		cerr << "Case " << n << " failed: returned " << have.size() << " elements; expected " << need.size() << " elements.";
		print( have );
		print( need );
		return;
	}
	for( int i= 0; i < have.size(); i++ ) {
		if( have[i] != need[i] ) {
			cerr << "Case " << n << " failed. Expected and returned array differ in position " << i << ".";
			print( have );
			print( need );
			return;
		}
	}
	cerr << "Case " << n << " passed." << endl;
}
static void eq( int n, string have, string need ) {
	if ( have == need ) {
		cerr << "Case " << n << " passed." << endl;
	} else {
		cerr << "Case " << n << " failed: expected ";
		print( need );
		cerr << " received ";
		print( have );
		cerr << "." << endl;
	}
}

int main() {
	{
		string first_slimeARRAY[] = {"1", "0", "0", "0", "0", "0", "0", "0", "0", "0"};
		vector <string> first_slime( first_slimeARRAY, first_slimeARRAY+ARRSIZE(first_slimeARRAY) );
		string second_slimeARRAY[] = {"1", "0", "0", "0", "0", "0", "0", "0", "0", "0"};
		vector <string> second_slime( second_slimeARRAY, second_slimeARRAY+ARRSIZE(second_slimeARRAY) );
		string third_slimeARRAY[] = {"1", "0", "0", "0", "0", "0", "0", "0", "0", "0"};
		vector <string> third_slime( third_slimeARRAY, third_slimeARRAY+ARRSIZE(third_slimeARRAY) );
		SlimeXSlimeRancher theObject;
		eq(3, theObject.train(first_slime, second_slime, third_slime),0LL);
	}
	{
		string first_slimeARRAY[] = {"1 6 2"};
		vector <string> first_slime( first_slimeARRAY, first_slimeARRAY+ARRSIZE(first_slimeARRAY) );
		string second_slimeARRAY[] = {"1 3 5"};
		vector <string> second_slime( second_slimeARRAY, second_slimeARRAY+ARRSIZE(second_slimeARRAY) );
		string third_slimeARRAY[] = {"5 4 3"};
		vector <string> third_slime( third_slimeARRAY, third_slimeARRAY+ARRSIZE(third_slimeARRAY) );
		SlimeXSlimeRancher theObject;
		eq(0, theObject.train(first_slime, second_slime, third_slime),5LL);
	}
	{
		string first_slimeARRAY[] = {"3 2 1"};
		vector <string> first_slime( first_slimeARRAY, first_slimeARRAY+ARRSIZE(first_slimeARRAY) );
		string second_slimeARRAY[] = {"6 5 4"};
		vector <string> second_slime( second_slimeARRAY, second_slimeARRAY+ARRSIZE(second_slimeARRAY) );
		string third_slimeARRAY[] = {"9 8 7"};
		vector <string> third_slime( third_slimeARRAY, third_slimeARRAY+ARRSIZE(third_slimeARRAY) );
		SlimeXSlimeRancher theObject;
		eq(1, theObject.train(first_slime, second_slime, third_slime),0LL);
	}
	{
		string first_slimeARRAY[] = {"1 2", "3 4"};
		vector <string> first_slime( first_slimeARRAY, first_slimeARRAY+ARRSIZE(first_slimeARRAY) );
		string second_slimeARRAY[] = {"12 3 ", "4"};
		vector <string> second_slime( second_slimeARRAY, second_slimeARRAY+ARRSIZE(second_slimeARRAY) );
		string third_slimeARRAY[] = {"1 2 ", "34"};
		vector <string> third_slime( third_slimeARRAY, third_slimeARRAY+ARRSIZE(third_slimeARRAY) );
		SlimeXSlimeRancher theObject;
		eq(2, theObject.train(first_slime, second_slime, third_slime),36LL);
	}
	{
		string first_slimeARRAY[] = {"1 1 1 1000000000 1000000000 1000000000"};
		vector <string> first_slime( first_slimeARRAY, first_slimeARRAY+ARRSIZE(first_slimeARRAY) );
		string second_slimeARRAY[] = {"1000000000 1000000000 1000000000 1 1 1"};
		vector <string> second_slime( second_slimeARRAY, second_slimeARRAY+ARRSIZE(second_slimeARRAY) );
		string third_slimeARRAY[] = {"1 1 1 2 2 2"};
		vector <string> third_slime( third_slimeARRAY, third_slimeARRAY+ARRSIZE(third_slimeARRAY) );
		SlimeXSlimeRancher theObject;
		eq(3, theObject.train(first_slime, second_slime, third_slime),2999999997LL);
	}

}
*/
