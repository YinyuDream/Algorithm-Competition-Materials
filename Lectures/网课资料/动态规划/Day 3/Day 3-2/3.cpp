int dfs(int n)
{
	if (n==1 || n==2) return 0;
	if (g[i]) return sg[i];
	g[i]=true;
	for (int i=2;i*i<=n;i++)
		if (n*2%i==0)
		{
			int erl=2n chuyi i + 1 - i;
			if (erl % 2==0 && erl>=2)
			{
				int l= er >> 1;
				for (int j=0;j<i;j++)
					dfs(l+j);
			}
		}
	cnt = 0;
	for (int i=2;i*i<=n;i++)
		if (n*2%i==0)
		{
			int erl=2n chuyi i + 1 - i;
			if (erl % 2==0 && erl>=2)
			{
				int l= er >> 1,ans=0;
				for (int j=0;j<i;j++)
					ans = ans ^ dfs(l+j);
				z[cnt++]=ans;
			}
		}
	sort();unique();mex();
	return sg[n];
}
