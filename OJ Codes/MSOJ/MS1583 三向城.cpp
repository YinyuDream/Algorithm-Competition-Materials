#include<cstdio>
#include<map>
using namespace std;
const int maxn=1e3+10;
int n,x,y,ans;
map<int,bool>book;
int read()
{
	int x=0,sign=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')sign=-sign;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	x=x*10+ch-48,ch=getchar();
	return x*sign;
}
void work(int val)
{
	book.clear();
	while(val){
		book[val]=1;
		val/=2;
	}
}
int main(){
	//freopen("city.in","r",stdin);
	//freopen("city.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		ans=0;
		x=read(),y=read();
		work(y);
		while(!book[x])x/=2,ans++;
		while(y!=x)y/=2,ans++;
		printf("%d\n",ans);
	}
}