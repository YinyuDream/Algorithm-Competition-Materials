#include<algorithm>

const int k=4;
const int base=10000;

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
		for (int a=1;a<=l;a+=k)
		{
			n++;
			int bit=1;
			for (int b=a;b<=a+k-1 && b<=l;b++)
			{
				z[n] = z[n] + (s[b]-'0') * bit;
				bit = bit * 10;
			}
		}
	}

	void print()
	{
		printf("%d",z[n]);
		for (int a=n-1;a>=1;a--)
			printf("%04d",z[a]);
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
		c.z[i+1] += c.z[i]/base;
		c.z[i] = c.z[i]%base;
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
		c.z[i+1] += c.z[i]/base;
		c.z[i] = c.z[i]%base;
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
