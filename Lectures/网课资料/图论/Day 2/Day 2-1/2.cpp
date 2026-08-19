int front=1,tail=1;
q[1]=1;
vis[1]=true;

for (;front<=tail;)
{
	int now=q[front++];

	for (int i=first[now];i!=0;i=ed[i].next)
		if (!vis[ed[i].e])
		{
			q[++tail]=ed[i].e;
			vis[ed[i].e]=true;
		}
}
for (int i=n;i>=1;i--)
{
	int now=q[i];
	size[now]=1;
	for (int i=first[now];i!=0;i=ed[i].next)
		if (size[ed[i].e])
			size[now] += size[ed[i].e];
}
l[1]=1;r[1]=n;
for (int i=1;i<=n;i++)
{
	int now=q[i];
	int x=l[now]+1;
	for (int i=first[now];i!=0;i=ed[i].next)
		if (size[ed[i].e] < size[now])
		{
			l[ed[i].e] = x;
			r[ed[i].e] = l[ed[i].e] + size[ed[i].e] - 1;
			x = r[ed[i].e]+1;
		}
}
for (int i=1;i<=n;i++)
	q[l[i]] = i;

