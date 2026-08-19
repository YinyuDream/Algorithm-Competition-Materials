#include<algorithm>

char s[2333];

struct gaojing
{
	int n,z[2333];

	gaojing()
	{
		n=1;
		memset(z,0,sizeof(z));
	}
	
	void init()
	{
		scanf("%s",s+1);
		int l=strlen(s+1);
		reverse(s+1,s+l+1);

		n = l;
		for (int a=1;a<=n;a++)
			z[a] = s[a]-'0';
	}

	void print()
	{
		for (int a=n;a>=1;a--)
			printf("%d",z[a]);
	}
};


gaojing operator+(const gaojing &a,const gaojing &b)
{
	gaojing c;
	c.n = max(a.n,b.n);
	for (int i=1;i<=c.n;i++)
		c.z[i] = a.z[i] + b.z[i];
	for (int i=1;i<=c.n;i++)
	{
		c.z[i+1] += c.z[i]/10;
		c.z[i] = c.z[i]%10;
	}
	if (c.z[c.n+1] != 0) c.n++;
	return c;
}


gaojing operator*(const gaojing &a,const gaojing &b)
{
	gaojing c;
	c.n = a.n + b.n;
	for (int i=1;i<=a.n;i++)
		for (int j=1;j<=b.n;j++)
			c.z[i+j-1] += a.z[i] * b.z[j];
	for (int i=1;i<=c.n;i++)
	{
		c.z[i+1] += c.z[i]/10;
		c.z[i] = c.z[i]%10;
	}
	while (c.n != 1 && c.z[c.n] == 0)
		c.n--;
	return c;
}


bool operator<(const gaojing &a,const gaojing &b)
{
	if (a.n!=b.n) return a.n<b.n;
	for (int i=a.n;i>=1;i--)
		if (a.z[i] != b.z[i]) return a.z[i]<b.z[i];
	return false;
}

bool operator<=(const gaojing &a,const gaojing &b)
{
	if (a.n!=b.n) return a.n<b.n;
	for (int i=a.n;i>=1;i--)
		if (a.z[i] != b.z[i]) return a.z[i]<b.z[i];
	return true;
}


gaojing a,b;
if (a<=b) printf("gg");
else printf("ggg");

gaojing z[2333];
sort(z+1,z+n+1);





