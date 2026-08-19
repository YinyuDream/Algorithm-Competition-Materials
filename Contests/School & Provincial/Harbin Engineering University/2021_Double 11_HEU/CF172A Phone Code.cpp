#include<bits/stdc++.h>
using namespace std;
const int maxn=30010,MAX_LEN=30;
int n,len;
char num[maxn][MAX_LEN];
bool check(int pos)
{
	for(int i=2;i<=n;i++)
		if(num[i][pos]!=num[1][pos])
			return false;
	return true;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%s",num[i]+1);
	for(int i=1;;i++)
		if(!check(i)){
			printf("%d",i-1);
			return 0;
		}
	return 0;
}