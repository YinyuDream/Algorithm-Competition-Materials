#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1e6+1e5;
char s[maxn];
int len,t,sum[maxn][26];
long long ans=0;
bool check(int l,int r){
	for(int i=0;i<l;i++) if(s[l-i]!=s[r-i]) return 1;
	return 0;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf(" %s",s+1);
		len=strlen(s+1);
		if(len<3){
			puts("0");
			continue;
		}
		for(int i=1;i<=len;i++){
			for(int j=0;j<26;j++) sum[i][j]=sum[i-1][j];
			sum[i][s[i]-'a']++;
		}
		int tmp,tql;
		for(int i=1;i<=len-2;i++){//a
			tmp=0;
			for(int j=0;j<26;j++) if(sum[i][j]&1) tmp++;
			for(int j=i+1;j<len;j++){//b
				tql=0;
				for(int p=0;p<26;p++) if((sum[len][p]-sum[j][p])&1) tql++;
				if(tql>=tmp) ans++;
				for(int k=j+j;k<len;k+=j){
					if(check(j,k)) break;
					tql=0;
					for(int p=0;p<26;p++) if((sum[len][p]-sum[k][p])&1) tql++;
					if(tql>=tmp) ans++;
				}//c
			}
		}
		printf("%lld\n",ans);
		ans=0;
	}
	return 0;
}
