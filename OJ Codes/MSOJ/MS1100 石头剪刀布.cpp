#include<cstdio>
using namespace std;
int N,NA,NB;
int A[110],B[110];
int a,b;
int main()
{
	scanf("%d%d%d",&N,&NA,&NB);
	for(int i=1;i<=NA;i++)scanf("%d",&A[i]);
	for(int i=1;i<=NB;i++)scanf("%d",&B[i]);
	for(int i=1;i<=N;i++)A[i+NA]=A[i];
	for(int i=1;i<=N;i++)B[i+NA]=B[i];
	for(int i=1;i<=N;i++)
	{
		if((A[i]==5&&B[i]==0)||(A[i]==2&&B[i]==5)||(A[i]==0&&B[i]==2))a++;
		if((A[i]==5&&B[i]==2)||(A[i]==2&&B[i]==0)||(A[i]==0&&B[i]==5))b++;
	}
	if(a>b)printf("A");
	else if(a==b)printf("draw");
	else printf("B");
	return 0;
}
