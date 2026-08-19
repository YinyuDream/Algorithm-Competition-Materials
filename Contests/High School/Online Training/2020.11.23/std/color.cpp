#include <bits/stdc++.h>
#define fo(a,b,c) for (a=b; a<=c; a++)
#define fd(a,b,c) for (a=b; a>=c; a--)
#define ll long long
#define file
using namespace std;

int a[201][30001],n,m,i,j,k,l,I,len;
char st[10485760],ch;

void Write(int x)
{
	char St[21];
	int i=0;
	while (x) St[++i]=x%10+'0',x/=10;
	while (i) st[++len]=St[i--];
}

int main()
{
	freopen("color.in","r",stdin);
	#ifdef file
	freopen("color.out","w",stdout);
	#endif
	
	scanf("%d%d",&n,&m);
	if (m>n*(n*2-1)) {printf("-1\n");return 0;}
	fo(i,0,n*2-2)
	{
		l=0;
		fo(j,0,n*2-2)
		{
			k=(i-j+(n*2-1))%(n*2-1);
			if (j!=k)
			{
				if (j<k)
				{
					++l;
					fo(I,i*n+1,(i+1)*n)
					a[j+1][I]=a[k+1][I]=(l+I)%n+1;
				}
			}
			else
			{
				fo(I,i*n+1,(i+1)*n)
				a[j+1][I]=a[n*2][I]=(n+I)%n+1;
			}
		}
	}
	
	len=-1;
	fo(i,1,n*2)
	{
		fo(j,1,m) Write(a[i][j]),st[++len]=' ';
		st[++len]='\n';
	}
	fwrite(st,1,len,stdout);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}