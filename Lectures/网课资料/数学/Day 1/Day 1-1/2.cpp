

gcd(a,0) = gcd(0,a) = a

int gcd(int a,int b)
{
	if (b==0) return a;
	else return gcd(b,a%b);
}

//__gcd(a,b);
