#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1e6+10;
char s[maxn];
int n,pos1,pos2,pos3,pos4,ans;
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++)
		if(s[i]=='['){
			pos1=i;
			break;
		}
	for(int i=n;i>=pos1+1;i--)
		if(s[i]==']'){
			pos2=i;
			break;
		}
	for(int i=pos1+1;i<=pos2-1;i++)
		if(s[i]==':'){
			pos3=i;
			break;
		}
	for(int i=pos2-1;i>=pos3+1;i--)
		if(s[i]==':'){
			pos4=i;
			break;
		}
	if(pos1==0||pos2==0||pos3==0||pos4==0)return puts("-1"),0;
	for(int i=pos3+1;i<=pos4-1;i++)
		ans+=(s[i]=='|');
	printf("%d",ans+4);
	return 0;
}
