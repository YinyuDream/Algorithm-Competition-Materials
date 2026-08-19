#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=100010;
struct nod{int a,b;}s[maxn];
int f[maxn];
int n,h=0,m;
bool cmp(nod a,nod b){
	if(a.a==b.a)return a.b<b.b;
	return a.a<b.a;
}
int main(){
	memset(f,-1,sizeof(f));
	scanf("%d",&n);f[0]=0;
	for(int i=1;i<=n;i++){
		scanf("%d%d",&s[i].a,&s[i].b);
		f[0]+=s[i].a;
	}
	sort(s+1,s+n+1,cmp);
	scanf("%d",&m);
	for(int i=1;i<=n;i++){
		for(int j=h;j>=0;j--){
			if(f[j]+s[i].b>=m){
				f[j+1]=max(f[j+1],f[j]-s[i].a);
			}if(f[h+1]>=0)h++;
		}
	}printf("%d\n",h);
}
