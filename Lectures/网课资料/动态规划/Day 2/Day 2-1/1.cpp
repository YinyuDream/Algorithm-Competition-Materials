v_[i] w_[i] k[i]

int cnt=0;
for (int i=1;i<=n;i++)
{
	int r=1;
	while (r<=k[i])
	{
		cnt ++;
		v[cnt] = v_[i] * r;
		w[cnt] = w_[i] * r;
		k[i] -= r;
		r = r*2;
	}
	if (k[i]!=0)
	{
		cnt ++;
		v[cnt] = v_[i] * k[i];
		w[cnt] = w_[i] * k[i];
	}
}
