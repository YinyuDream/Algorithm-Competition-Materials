/*
给出n*m (m<=10,n<2^31)的方格棋盘，用1*2的长方形骨牌不重叠地覆盖这个棋盘，求覆盖满的方案数。
*/

/*
Sol :SC+MatrixPower
Time:Omega(4^m*logn)
Spc :O(4^m)
*/

#include<cstdio>
const int mlog=32,mnot0=200000,maxs=1<<10,mod=10000;
typedef int matrix[maxs][maxs];
struct element
{
	int p,q,key;
};
struct sm
{
	element data[mnot0];
	int hp[maxs],size;
	void convert(matrix a);
}tmp[2],sg;
int n,m,ms,sp=0;
matrix tm;
bool bin[mlog];

void dfs(int p,int s1,int s2)
{
	if(p>m)return;
	if(p==m)tm[s1][s2]++;
	dfs(p+1,s1*2,s2*2+1);
	dfs(p+1,s1*2+1,s2*2);
	dfs(p+2,s1*4+3,s2*4+3);
}

void sm::convert(matrix a)
{
	size=0;
	for(int i=0,j,flg;i<ms;i++)
		for(j=0,hp[i]=0,flg=1;j<ms;j++)
			if(a[i][j])
			{
				data[++size]=(element){i,j,a[i][j]};
				if(flg)hp[i]=size,flg=0;
			}
}

void multiply(sm &a,sm &b,sm &c)
{
	for(int i=0;i<ms;i++)
		for(int j=i;j<ms;j++)
			tm[i][j]=tm[j][i]=0;
	for(element *da=a.data+1,*db;da<=a.data+a.size;da++)
		for(db=b.data+b.hp[da->q];da->q==db->p && db<=b.data+b.size;db++)
			tm[da->p][db->q]+=da->key*db->key,
			tm[da->p][db->q]%=mod;
	c.convert(tm);
}

int main()
{
	scanf("%d%d",&n,&m);
	if(n&m&1){printf("0\n");return 0;}
	if(n<m)n^=m,m=n^m,n^=m;
	dfs(0,0,0);
	
	ms=1<<m;	
	sg.convert(tm);
	for(int tn=n;tn;bin[++sp]=tn&1,tn/=2);
	tmp[sp&1]=sg;
	for(int i=sp-1;i>=1;i--)
	{
		multiply(tmp[i&1^1],tmp[i&1^1],tmp[i&1]);
		if(bin[i])multiply(tmp[i&1],sg,tmp[i&1]);
	}
	printf("%d\n",tmp[1].data[tmp[1].size].key);
	return 0;
}
