#include<cstdio>
#include<cstring>
using namespace std;
typedef unsigned long long ull;
const int maxn=1e6+10;
int n;
char a[maxn],b[maxn];
ull hashb[maxn],pow[maxn];
void Hash(int lena,int lenb)
{
	memset(hashb,0,sizeof hashb);
	ull hash_a=0;
	int ans=0; 
	for(int i=0;i<lena;i++)
		hashb[0]=hashb[0]*131+b[i],hash_a=hash_a*131+a[i];
	for(int i=0;i+lena<=lenb;i++){
		if(hashb[i]==hash_a)ans++;
		hashb[i+1]=(hashb[i]-b[i]*pow[lena-1])*131+b[i+lena];
	}
	printf("%d\n",ans);
} 
int main(){
	pow[0]=1;
	for(int i=1;i<maxn;i++)
		pow[i]=pow[i-1]*131;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("\n%s\n%s",a,b);
		Hash(strlen(a),strlen(b)); 
	}
	return 0;
} 