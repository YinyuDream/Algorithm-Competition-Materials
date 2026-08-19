int f[233];
bool g[233];

int dfs(int n)
{
	if (n==0) return 0;
	if (n==1) return 1;
	if (g[n]) return f[n];
	f[n]=dfs(n-1)+dfs(n-2);
	g[n]=true;
	return f[n];
}


