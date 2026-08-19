void build(int l,int r,int rt)
{
	if (l==r)
	{
		add_edge(rt+(n<<1),z[l].p<=n?z[l].p+n:z[l].p-n);
		return;
	}
	int m=(l+r)>>1;
	build(lson);
	build(rson);
	add_edge(rt+(n<<1),(rt<<1)+(n<<1));
	add_edge(rt+(n<<1),(rt<<1|1)+(n<<1));
}