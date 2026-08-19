/*
4
3 4 5 6

5
3 6 7 8 2 
*/ 
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAX_N 1010
static int a[MAX_N];//用来保存序列 
static int dp[MAX_N][MAX_N];//i  j  用来保存删除第i个数到第j个数所得到的最优值 
void dp1(int n)
{
	int j = 0;
	for(int r = 3;r <= n;r ++ ){
		for(int i = 1;;i ++ ){
			int j = i + r -1;
			for(int k = i + 1;k <= j - 1;k ++ ){
				dp[i][j] = max(dp[i][j],dp[i][k]+dp[k][j]+a[i]*a[k]*a[j]);
			}
			if(j >= n) break;
		}
	} 
	cout << "删除n-2个数之后，得到的最大值为：" << endl;
	cout << dp[1][n] << endl;
}
int main()
{
	int n;
	cout << "请输入序列的位数n" << endl;
	while(cin >> n,n){
		for(int i = 1;i <= n;i ++ )cin >> a[i];
		memset(dp,0,MAX_N*MAX_N);
		for(int i = 1;i <= n - 1;i ++ ) dp[i][i + 1] = 0;
		dp1(n);
		cout << "请输入序列的位数n" << endl;
	}  
	return 0;
}
