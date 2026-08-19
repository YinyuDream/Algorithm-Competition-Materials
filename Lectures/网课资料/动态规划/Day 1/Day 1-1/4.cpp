z[233];
f[233];
a[233];

cnt = 0;
for (int i=1;i<=n;i++)
{
	f[i]=1;
	erfen();
	for (int j=1;j<=cnt;j++)
		if (a[z[j]] < a[i]) f[i] = max(f[i],j+1);

	if (f[i]>cnt) cnt++,z[cnt]=i;
	else
	{
		if (a[i] < a[z[f[i]]]) z[f[i]] = i;
	}
}
