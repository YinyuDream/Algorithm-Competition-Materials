/*
131. Hardwood floor 
Time Limit: 0.5 sec, Memory Limit: 600 KB 

The banquet hall of Computer Scientists' Palace has a rectangular form of the size M x N (1<=M<=9, 1<=N<=9). It is necessary to lay hardwood floors in the hall. There are wood pieces of two forms:
1) rectangles (2x1) 
2) corners (squares 2x2 without one 1x1 square) 
You have to determine X - the number of ways to cover the banquet hall. 
Remarks. The number of pieces is large enough. It is not allowed to leave empty places, or to cover any part of a surface twice, or to saw pieces.

Input
The first line contains natural number M. The second line contains a natural number N. 

Output
First line should contain the number X, or 0 if there are no solutions. 

Sample Input
2 3
Sample Output
5
*/

/*
Sol :SCR
Time:...
Spc :O(2^m)
*/
#include<cstdio>
#include<cstring>
const int mn=9;
int ln,n,m;
long long f[2][1<<mn];

void dfs(int p,int s1,int s2,bool b1,bool b2)
{
	if(p>m)
    {
    	if(!b1&!b2)f[ln&1][s1]+=f[1-ln&1][s2];
        return;
    }
    if(!b1&!b2)
    {
    	dfs(p+1,s1*2+1,s2*2,0,0);
        dfs(p+1,s1*2+1,s2*2,1,0);
        dfs(p+1,s1*2+1,s2*2,0,1);
    }
    if(!b1)
    {
    	dfs(p+1,s1*2+1,s2*2+1-b2,1,0);
		dfs(p+1,s1*2+1,s2*2+1-b2,1,1);
    }
    if(!b2)
    	dfs(p+1,s1*2+b1,s2*2,1,1);
	dfs(p+1,s1*2+b1,s2*2+1-b2,0,0);
}
int main()
{
	scanf("%d%d",&n,&m);
	if(n<m)n^=m,m=n^m,n^=m;
	f[0][(1<<m)-1]=1;
	for(ln=1;ln<=n;ln++)
	{
		dfs(1,0,0,0,0);
		memset(f[1-ln&1],0,sizeof(f[0]));
	}
	printf("%I64d\n",f[n&1][(1<<m)-1]);

	return 0;
}
