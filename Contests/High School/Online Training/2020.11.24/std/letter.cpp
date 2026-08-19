#include<cstdio>
#include<cstring>
#define Z int
#define C char
#define V void
#define S(s) scanf("%s",s+1)
#define P(n) printf("%d",n)
#define M(f) memset(f,127,sizeof f)
#define _(g,f) memcpy(g,f,sizeof f)
#define F(i,a,b) for(Z i=a,_b=b;i<=_b;i++)
#define W while
#define sm(a,b) ((a)<(b)?(a):(b))
#define I if
#define nx 5001
#define inf 2139062143
C s[nx];
Z n,a[nx],u,v,y,f[2][nx][4],g,ans;
V up(Z&x,Z y){x=sm(x,y);}
Z main(){
	freopen("letter.in","r",stdin);
	freopen("letter.out","w",stdout);
	S(s);
	W(s[n+1])n++;
	F(i,1,n)a[i]=s[i]-'A';
	M(f),f[u=0][0][3]=n,v=1;
	F(i,0,n-1){
		y=i?a[i]:3;
		F(j,0,i)F(x,0,3)I((g=f[u][j][x])<inf){
			I(a[i+1]!=x&&a[i+1]!=y){
				up(f[v][j+1][y],g+2);
				I(j>2)up(f[v][j-2][j==3?3:y],g);
			}
			I(a[i+1]==x)up(f[v][j-1][j==2?3:3-x-y],g);
			I(a[i+1]==y)up(f[v][j][x],g);
		}
		F(j,0,i)_(f[u][j],f[v][j]),M(f[u][j]);
		u^=1,v^=1;
	}
	ans=inf;
	F(i,0,n)F(x,0,3)ans=sm(ans,f[u][i][x]);
	P(ans);
}