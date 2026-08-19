#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAX_N 16
static long long m[MAX_N];
static long long dp[MAX_N][MAX_N];
void Max_equ(int n,int k)
{
	for(int i = 2;i <= n;i ++ ){	//从前两个数开始拓展到n个 
		int index = min(i - 1,k);	//找出运算符和*的最小值 
		for(int j = 1;j <= index;j ++ ) 
			for(int l = 2;l <= i;l ++ ) 
				dp[i][j] = max(dp[i][j],dp[l-1][j-1]*(m[i]-m[l-1]));
	}
	cout << dp[n][k] << endl;
}
int main()
{
	int n,k;
	int a;
	cin >> n >> k;
	for(int i = 1;i <= n;i ++ ){
		cin >> a;
		if(i == 1) {
			m[i] = a;
			dp[i][0] = m[i];
		}
		else{
			m[i] = m[i-1] + a;
			dp[i][0] = m[i];
		}
		
	} 
	Max_equ(n,k);
	return 0;
 } 

