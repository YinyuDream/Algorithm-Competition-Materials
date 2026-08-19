int size=0;
for (int i=1;i<=n;i++)
	if (!in[i])
	{
		size++;
		q[size]=i;
	}

for (int i=1;i<=n;i++)
{
	int now=q[i];
	for (int j=first[now];j!=0;j=ed[j].next)
	{
		int e=ed[j].e;
		in[e]--;
		if (!in[e])
		{
			size++;
			q[size]=e;
		}
	}
}
