void insert(int l,int r,int rt,int nowl,int nowr,int p)
{
	if (nowl<=l && r<=nowr)
	{
		add_edge(p,rt+(n<<1));
		return;
	}
	int m=(l+r)>>1;
	if (nowl<=m) insert(lson,nowl,nowr,p);
	if (m<nowr) insert(rson,nowl,nowr,p);
}