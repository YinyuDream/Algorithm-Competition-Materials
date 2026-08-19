#include<cstdio>
#include<cstring>
#define Z int
#define C char
#define V void
#define L long long
#define S scanf
#define P printf
#define M(f) memset(f,127,sizeof f)
#define F(i,a,b) for(L i=a;i<=b;i++)
#define W while
#define sm(a,b) ((a)<(b)?(a):(b))
#define I if
#define E else
#define R return
#define mx 31
#define nx 1000001
#define p 998244353
C s[nx];
L t,n,f[nx][2][2],tot,ans;
L v[3][3][3][2],cnt;
L ori[mx],to[mx],bi[70],one[mx][mx],a[mx][mx],b[mx][mx];
L pw(L x,L y){
	I(!y)R 1;
	L u=pw(x,y>>1);
	R u*u%p*(y&1?x:1)%p;
}
L check1(L w,L x,L y){R!(x+y==2||(x+y==0&&s[w]==s[w-1]));}
L check2(L w,L x,L y){R!(x+y==2||(x+y==0&&w>1&&s[w]==s[w-2]));}
V dp(){
	ans=nx,M(f),f[0][0][0]=0;
	F(i,0,n-1)F(x,0,1)F(y,0,1)I(f[i][x][y]<nx)
	F(z,0,1)I(check1(i+1,y,z)&&check2(i+1,x,z))
	f[i+1][y][z]=sm(f[i+1][y][z],f[i][x][y]+z);
	F(x,0,1)F(y,0,1)ans=sm(ans,f[n][x][y]);
	P("%lld",ans<nx?ans:-1);
}
V dfs(L _0,L _1,L _2,L o){
	I(v[_0][_1][_2][o])R;
	v[_0][_1][_2][o]=++cnt;
	L g[2][2],_g[2][2],w;
	g[0][0]=_0,g[0][1]=_1,g[1][0]=_2;
	//not the same
	M(_g),w=2;
	F(x,0,1)F(y,0,1)I(x+y<2&&g[x][y]<2)F(u,0,1)I(u+x<2&&u+y<2)_g[y][u]=sm(_g[y][u],g[x][y]+u);
	F(x,0,1)F(y,0,1)I(x+y<2&&_g[x][y]<=2)w=sm(w,_g[x][y]);
	F(x,0,1)F(y,0,1)I(x+y<2)_g[x][y]<=2?_g[x][y]-=w:_g[x][y]=2;
	dfs(_g[0][0],_g[0][1],_g[1][0],0);
	//
	I(o)dfs(2,2,2,1);
	//s[i+1]=s[i] or s[i+1]=s[i-1]
	I(!o){
		M(_g),w=2;
		F(x,0,1)F(y,0,1)I(x+y<2&&g[x][y]<2)F(u,0,1)I(u+x<2&&u+y==1)_g[y][u]=sm(_g[y][u],g[x][y]+u);
		F(x,0,1)F(y,0,1)I(x+y<2&&_g[x][y]<=2)w=sm(w,_g[x][y]);
		F(x,0,1)F(y,0,1)I(x+y<2)_g[x][y]<=2?_g[x][y]-=w:_g[x][y]=2;
		dfs(_g[0][0],_g[0][1],_g[1][0],1);
		M(_g),w=2;
		F(x,0,1)F(y,0,1)I(x+y<2&&g[x][y]<2)F(u,0,1)I(u+x==1&&u+y<2)_g[y][u]=sm(_g[y][u],g[x][y]+u);
		F(x,0,1)F(y,0,1)I(x+y<2&&_g[x][y]<=2)w=sm(w,_g[x][y]);
		F(x,0,1)F(y,0,1)I(x+y<2)_g[x][y]<=2?_g[x][y]-=w:_g[x][y]=2;
		dfs(_g[0][0],_g[0][1],_g[1][0],0);
	}
}
V preprocessing(){
	dfs(0,1,1,0),dfs(2,0,0,1);
	L g[2][2],_g[2][2],w,st;
	F(_0,0,2)F(_1,0,2)F(_2,0,2)F(o,0,1)I(st=v[_0][_1][_2][o]){
		g[0][0]=_0,g[0][1]=_1,g[1][0]=_2;
		//not the same
		M(_g),w=2;
		F(x,0,1)F(y,0,1)I(x+y<2&&g[x][y]<2)F(u,0,1)I(u+x<2&&u+y<2)_g[y][u]=sm(_g[y][u],g[x][y]+u);
		F(x,0,1)F(y,0,1)I(x+y<2&&_g[x][y]<=2)w=sm(w,_g[x][y]);
		F(x,0,1)F(y,0,1)I(x+y<2)_g[x][y]<=2?_g[x][y]-=w:_g[x][y]=2;
		one[st][v[_g[0][0]][_g[0][1]][_g[1][0]][0]]+=24+o;
		I(w<2)
		one[st+15][v[_g[0][0]][_g[0][1]][_g[1][0]][0]+15]+=24+o,
		one[st][v[_g[0][0]][_g[0][1]][_g[1][0]][0]+15]+=(24+o)*w;
		//
		I(o)one[st][v[2][2][2][1]]++;
		//s[i+1]=s[i] or s[i+1]=s[i-1]
		I(!o){
			M(_g),w=2;
			F(x,0,1)F(y,0,1)I(x+y<2&&g[x][y]<2)F(u,0,1)I(u+x<2&&u+y==1)_g[y][u]=sm(_g[y][u],g[x][y]+u);
			F(x,0,1)F(y,0,1)I(x+y<2&&_g[x][y]<=2)w=sm(w,_g[x][y]);
			F(x,0,1)F(y,0,1)I(x+y<2)_g[x][y]<=2?_g[x][y]-=w:_g[x][y]=2;
			one[st][v[_g[0][0]][_g[0][1]][_g[1][0]][1]]++;
			I(w<2)
			one[st+15][v[_g[0][0]][_g[0][1]][_g[1][0]][1]+15]++,
			one[st][v[_g[0][0]][_g[0][1]][_g[1][0]][1]+15]+=w;
			M(_g),w=2;
			F(x,0,1)F(y,0,1)I(x+y<2&&g[x][y]<2)F(u,0,1)I(u+x==1&&u+y<2)_g[y][u]=sm(_g[y][u],g[x][y]+u);
			F(x,0,1)F(y,0,1)I(x+y<2&&_g[x][y]<=2)w=sm(w,_g[x][y]);
			F(x,0,1)F(y,0,1)I(x+y<2)_g[x][y]<=2?_g[x][y]-=w:_g[x][y]=2;
			one[st][v[_g[0][0]][_g[0][1]][_g[1][0]][0]]++;
			I(w<2)
			one[st+15][v[_g[0][0]][_g[0][1]][_g[1][0]][0]+15]++,
			one[st][v[_g[0][0]][_g[0][1]][_g[1][0]][0]+15]+=w;
		}
	}
}
Z main(){
	freopen("palindrome.in","r",stdin);
	freopen("palindrome.out","w",stdout);
	S("%lld%lld\n",&t,&n);
	I(t==1){S("%s",s+1),dp();R 0;}
	I(n==1){P(0);R 0;}
	preprocessing();
	n-=2;
	W(n)bi[++bi[0]]=n&1,n>>=1;
	F(i,1,30)a[i][i]=1;
	W(bi[0]){
		F(i,1,30)F(j,1,30){
			b[i][j]=0;
			F(k,1,30)(b[i][j]+=a[i][k]*a[k][j])%=p;
		}
		I(bi[bi[0]--])F(i,1,30)F(j,1,30){
			a[i][j]=0;
			F(k,1,30)(a[i][j]+=b[i][k]*one[k][j])%=p;
		}E F(i,1,30)F(j,1,30)a[i][j]=b[i][j];
	}
	ori[v[0][1][1][0]]=26*25,ori[v[2][0][0][1]]=26,ori[v[2][0][0][1]+15]=26;
	F(i,1,30)I(ori[i])F(j,1,30)(to[j]+=ori[i]*a[i][j])%=p;
	F(i,1,15)(tot+=to[i])%=p;
	F(i,16,30)(ans+=to[i])%=p;
	F(o,0,1)(ans-=to[v[2][2][2][o]])%=p;
	(ans*=pw(tot,p-2))%=p,P("%lld",(ans+p)%p);
}