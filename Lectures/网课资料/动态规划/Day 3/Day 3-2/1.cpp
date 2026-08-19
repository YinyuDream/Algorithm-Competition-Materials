bool dfs(int s,int i)
{
	if (s==0) return false;
	if (g[s][i]) return f[s][i];
	g[s][i]=true;
	for (int j=1;j<=k*i && j<=s;j++)
		if (!dfs(s-j,j)) f[s][i]=true;
	return f[s][i];
}

s,k

bool win=false;
for (int i=1;i<s;i++)
	if (!dfs(s-i,i)) win=true;
