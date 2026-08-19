f[i]
g[i]
pre[i];

for (int i=1;i<=n;i++)
{
	f[i]=1;g[i]=1;pre[i]=0;
	for (int j=1;j<i;j++)
		if (a[j] < a[i]) 
		{
			int l=f[j]+1;
			if (l>f[i]) f[i]=l,g[i]=0,pre[i]=j;
			if (l==f[i]) g[i] += g[j];
		}
}

p
do
{
	z[++cnt] = p;
	p=pre[p];
while (p!=0);
reverse(z+1,z+cnt+1);
