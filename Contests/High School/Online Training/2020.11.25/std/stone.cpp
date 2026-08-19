#include<cstdio>
#include<cstdlib>
#include<algorithm>

const int LEN=1e7;
char ibuf[LEN],*ibufp=ibuf+LEN; const char *iendp=ibuf+LEN;
char obuf[LEN],*obufp=obuf; const char *oendp=obuf+LEN;

#define getc(___) (ibufp==iendp?(fread(ibuf,sizeof(char),LEN,stdin),*(ibufp=ibuf)++):*ibufp++)
#define putc(val) (obufp==oendp?(fwrite(obuf,sizeof(char),LEN,stdout),*(obufp=obuf)++=(val)):*obufp++=(val))
#define flush(__) (obufp!=obuf?fwrite(obuf,sizeof(char),obufp-obuf,stdout):-1)

void read_int (int &a) {
	char c=getc(); a=0;
	while (c<'0'||c>'9') c=getc();
	while (c>='0'&&c<='9') a=(a<<1)+(a<<3)-48+c,c=getc();
	return;
}

void print_int (int _val) {
	if (_val<10) { putc(_val+48); return; }
	print_int(_val/10); putc(_val%10+48);
	return;
}

const int INF=1e9+7;
const int MAX=3e5+7,SUMK=1e6+7,MAXP=20;

int n,depth[MAX],f[MAX][MAXP];

struct edge {
	int point,next;
} r[MAX<<1]; int last[MAX];

void link (int x,int y) {
	static int tot=0;
	r[++tot]=(edge){y,last[x]}; last[x]=tot;
	r[++tot]=(edge){x,last[y]}; last[y]=tot;
	return;
}

namespace LCA {
	
	int len,s[MAX<<1],place[MAX];
	int lg2[MAX<<1],w[MAXP];
	int val[MAX<<1][MAXP];
	
	void dfs (int now) {
		s[++len]=now; place[now]=len; depth[now]=depth[f[now][0]]+1;
		for (int i=last[now];i;i=r[i].next) {
			if (r[i].point==f[now][0]) continue;
				f[r[i].point][0]=now,dfs(r[i].point);
			s[++len]=now;
		} return;
	}
	
	void init () {
		
		dfs(1);
		
		for (int lim=2,val=0,p=0;p<=len;lim<<=1,val++)
			while (p<lim&&p<=len) lg2[p++]=val;
		for (int i=0;i<=lg2[len];i++) w[i]=1<<i;
		
		for (int i=1;i<=len;i++) val[i][0]=s[i];
		
		for (int p=1;p<=lg2[len];p++)
			for (int i=1;i<=len-w[p]+1;i++)
				val[i][p]=(depth[val[i][p-1]]<depth[val[i+w[p-1]][p-1]])?
					val[i][p-1]:val[i+w[p-1]][p-1];
		
		for (int p=1;p<=lg2[len];p++)
			for (int i=1;i<=n;i++)
				f[i][p]=f[f[i][p-1]][p-1];
		
		return;
		
	}
	
	int ask (int x,int y) {
		if (place[x]>place[y]) std::swap(x,y);
		int point=lg2[place[y]-place[x]+1];
		int left=val[place[x]][point],right=val[place[y]-w[point]+1][point];
		return depth[left]<depth[right]?left:right;
	}
	
	int jump (int cur,int dis) {
		for (int p=0;dis;p++,dis>>=1)
			if (dis&1) cur=f[cur][p];
		return cur;
	}
	
}

int q,k,p[SUMK];

int extra[MAX];

void modify (int cur,int val) {
	if (val<extra[cur])
		extra[cur]=val;
	return;
}

void solve () {
	if (k==1) { modify(p[1],0); return; }
	int xx=p[1],yy=p[2];
	int len=depth[xx]+depth[yy]-(depth[LCA::ask(xx,yy)]<<1);
	for (int i=3,nl1,nl2;i<=k;i++) {
		nl1=depth[xx]+depth[p[i]]-(depth[LCA::ask(xx,p[i])]<<1);
		nl2=depth[yy]+depth[p[i]]-(depth[LCA::ask(yy,p[i])]<<1);
		if (nl1>nl2&&nl1>len) yy=p[i],len=nl1;
		else if (nl2>len) xx=p[i],len=nl2;
	}
	if (depth[xx]<depth[yy]) std::swap(xx,yy);
	if (len&1) {
		int down=LCA::jump(xx,len>>1);
		modify(down,(len+1)>>1); modify(f[down][0],(len+1)>>1);
	} else modify(LCA::jump(xx,len>>1),len>>1);
}

int ans[MAX];

void dfs1 (int now) {
	ans[now]=extra[now];
	for (int i=last[now];i;i=r[i].next) {
		if (r[i].point==f[now][0]) continue;
		dfs1(r[i].point);
		if (ans[r[i].point]+1<ans[now])
			ans[now]=ans[r[i].point]+1;
	} return;
}

void dfs2 (int now,int val) {
	if (val<ans[now]) ans[now]=val;
	if (extra[now]<val) val=extra[now];
	int min1=INF,min2=INF;
	for (int i=last[now];i;i=r[i].next) {
		if (r[i].point==f[now][0]) continue;
		if (ans[r[i].point]<min1) min2=min1,min1=ans[r[i].point];
		else if (ans[r[i].point]<min2) min2=ans[r[i].point];
	}
	for (int i=last[now],nowv;i;i=r[i].next) {
		if (r[i].point==f[now][0]) continue;
		nowv=val+1;
		if (ans[r[i].point]==min1) { if (min2+2<nowv) nowv=min2+2; }
		else if (min1+2<nowv) nowv=min1+2;
		dfs2(r[i].point,nowv);
	}
	return;
}

int main () {
	const int SIZE_ADD=40<<20;
	asm ( "movq %0, %%rsp\n"::"r"((char*)malloc(SIZE_ADD)+SIZE_ADD));
	freopen("stone.in","r",stdin);
	freopen("stone.out","w",stdout);
	
	read_int(n);
	for (int i=2,f;i<=n;i++)
		read_int(f),link(f,i);
	LCA::init();
	
	std::fill(extra+1,extra+n+1,INF);
	
	read_int(q);
	while (q--) {
		read_int(k);
		for (int i=1;i<=k;i++) read_int(p[i]);
		solve();
	}
	
	std::fill(ans+1,ans+n+1,INF);
	dfs1(1); dfs2(1,INF);
	
	for (int i=1;i<=n;i++,putc('\n'))
		print_int(ans[i]);
	flush();
	
	fclose(stdin); fclose(stdout);
	exit(0); //return 0;
}