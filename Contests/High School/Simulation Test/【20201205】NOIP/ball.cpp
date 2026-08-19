#include<cstdio>
using namespace std;
const int maxn=1000010;
int n,m,h[60][410],ans=0,tg1[maxn],tg2[maxn];
inline int read(){
	int sm=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9'){
		sm=sm*10-'0'+ch;
		ch=getchar();
	}
	return sm;
}
int col[60],tmp;
bool check(int i,int pl){
	for(int j=m;j>=1;j--){
		if(h[i][j]==col[pl]){
			tmp=j;
			return 1;
		}
	}
}
void change(int pl){
	col[pl]=h[pl][1];
	int now=2;
	while(col[pl]==h[pl][now]&&now<=m) now++;
	int zml=pl+1;
	while(now<=m){
		int flag=0;
		for(;zml<=n;){
			flag=zml;
			if(check(zml,pl)) break;
			else zml++;
		}
		for(int i=tmp;i<m;i++) h[flag][i]=h[flag][i+1];
		h[flag][m]=h[pl][m];
		for(int i=m;i>now;i--) h[pl][i]=h[pl][i-1];
		h[pl][now]=col[pl];
		if(tmp<m){
			for(int i=m;i>tmp;i--){
				ans++;
				tg1[ans]=flag;
				tg2[ans]=n+1;
			}
			ans++;
			tg1[ans]=pl;
			tg2[ans]=n+1;
			ans++;
			tg1[ans]=flag;
			tg2[ans]=pl;
			for(int i=m;i>=tmp;i--){
				ans++;
				tg1[ans]=n+1;
				tg2[ans]=flag;
			}
			ans++;
			tg1[ans]=flag;
			tg2[ans]=n+1;
			ans++;
			tg1[ans]=pl;
			tg2[ans]=flag;
			ans++;
			tg1[ans]=n+1;
			tg2[ans]=pl;
		}
		for(int i=now;i<=m;i++){
			ans++;
			tg1[ans]=pl;
			tg2[ans]=n+1;
		}
		ans++;
		tg1[ans]=flag;
		tg2[ans]=pl;
		now++;
		for(int i=now;i<=m;i++){
			ans++;
			tg1[ans]=n+1;
			tg2[ans]=pl;
		}
		ans++;
		tg1[ans]=n+1;
		tg2[ans]=flag;
	}
}
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) h[i][j]=read();
	}
	for(int i=1;i<n;i++) change(i);
	printf("%d\n",ans);
	for(int i=1;i<=ans;i++) printf("%d %d\n",tg1[i],tg2[i]);
	return 0;
}
