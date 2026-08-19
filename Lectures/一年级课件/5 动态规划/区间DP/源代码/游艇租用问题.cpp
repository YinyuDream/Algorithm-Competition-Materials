#include<iostream>
#include<cstring>
#include<algorithm>
#define MAX_N 1010
using namespace std;
static int ri[MAX_N][MAX_N];
static int fin[MAX_N][MAX_N];
void dp(int n)
{
	for(int r = 2;r <= n;r ++ ){
		for(int i = 1;i < n;i ++ ){
			int j = i + r - 1;
			fin[i][j] = fin[i][j-1] + ri[j-1][j];
			for(int k = i + 1;k <= j;k ++ ){
				int t = fin[i][k] +fin[k][j];
				if(fin[i][j]>t) fin[i][j] = t;
			}
		}
	}
	cout << "最优值" <<endl;
	cout << fin[1][n] <<endl;
}

int main()
{
	int n;
	cout << "请输入出租站的个数" << endl;
	cin >> n;
	for(int i = 1;i < n;i ++ ){
		for(int j = i + 1;j <= n;j ++ ){
			cin >> ri[i][j];
		}
	}
	dp(n);
	cout << "最优值表" << endl;
	for (int i = 1;i <= n;i ++ ){
		for(int j = 1;j <= n;j ++ ){
			cout << fin[i][j] << " ";
		}
		cout << endl;
	} 
	return 0;
 }
 /*分析：
  fin[i][j] 表示从i站到j站的最少租金
  最优子结构：
  fin[i][j] = fin[i][k] + r[k][j]; (i<=k<=j);
  先从r = 2开始迭代，r表示问题规模，当问题规模增加到n是，便可求出最优解。很简单的区间动规*/
