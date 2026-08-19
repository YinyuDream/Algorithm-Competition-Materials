int n,m;
O(n^3)
bianbiao -> O(nm) m±ßµÄÊıÁ¿
n<=100

n<=100000
bool dfs(int i)
{
	for (int j=1;j<=m;j++)
		if (match[i][j] && !use[j])
		{
			use[j]=true;
			if (!result[j] || dfs(result[j]))
			{
				result[j]=i;
				return true;
			}
		}
	return false;
}

int xiongyali()
{
	int ans=0;
	for (int i=1;i<=n;i++)
	{
		memset(use,false,sizeof(use));
		if (dfs(i)) ans++;
	}
	return ans;
}
