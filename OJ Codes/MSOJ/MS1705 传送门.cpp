#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e7+10;
int T,lens,lenb,top,nextn[maxn];
char s[maxn],a[maxn],b[maxn];
int next_ptr(int pt)
{
	while(s[pt]!=']')pt++;
	return pt;
}
int get_sum(int l,int r)
{
	int sum=0;
	for(int i=l+1;i<r;i++)
		sum=sum*10+s[i]-'0';
	return sum;
}
void work()
{
	for(int i=1;i<=lens;i++){
		if(s[i]<='z'&&s[i]>='a'){
			a[++top]=s[i];
		}else{
			int pt=next_ptr(i),num=get_sum(i,pt);
			num=min(num,lenb);
			for(int j=1;j<num;j++)
				a[++top]=s[i-1];
			i=pt;
		}
	}
}
void get_next()
{
	for(int i=2,j=0;i<=lenb;i++){
		while(j&&b[j+1]!=b[i])
		j=nextn[j];
		j+=(b[i]==b[j+1]);
		nextn[i]=j;
	}
}
bool check()
{
	for(int i=2,j=0;i<=top;i++){
		while(j&&b[j+1]!=a[i])
		j=nextn[j];
		j+=(a[i]==b[j+1]);
		if(j==lenb)return true;
	}
	return false;
}
int main(){
	//freopen("door.in","r",stdin);
	//freopen("door.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		top=0;
		scanf("\n%s\n%s",s+1,b+1);
		lens=strlen(s+1),lenb=strlen(b+1);
		work();
		get_next();
		if(check())puts("True");
		else puts("False");
	}
	return 0;
}