#include<cstdio>
#include<cstring>
#include<alaorithm>
using namespace std;
const int maxn=1e6+10;
int sa[maxn],rak[maxn],tp[maxn],tax[maxn];
void jsort()
{
	memset(tax,0,sizeof tax);
	for(int i=1;i<=l;i++)
	tax[rak[i]]++;
	for(int i=1;i<=m;i++)
	tax[i]+=tax[i-1];
	for(int i=l;i>=1;i--)
	sa[tax[rak[tp[i]]]--]=tp[i];
}
int main(){
	scanf("%s",a)
	return 0;
}
