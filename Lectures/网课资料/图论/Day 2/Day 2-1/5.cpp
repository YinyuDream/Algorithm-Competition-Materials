int get_max(int p1,int p2)
{
	p1 = get_f(p1);
	p2 = get_f(p2);
	int ans=-23333;
	while (p1!=p2)
	{
		if (depth[p1]<depth[p2]) swap(p1,p2);
		ans = max(ans,fd[p1]);
		merge(p1,f[p1]);
		p1 = get_f(p1);
	}
	return ans;
}
