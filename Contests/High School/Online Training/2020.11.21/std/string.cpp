#include<stdio.h>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
using namespace std;
const int N=600005;
int read() {
	int x=0,f=1;char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}
char ch[N];
string S[N];
vector<int>fuck;
int n,Q,block=400,len[N],hh[400][400],bel[N];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	n=read();Q=read();
	for(int i=1;i<=n;++i){
		scanf("%s",ch+1);
		len[i]=strlen(ch+1);
		for(int j=1;j<=len[i];++j)
		S[i].push_back(ch[j]);
		if(len[i]>block)fuck.push_back(i),bel[i]=fuck.size()-1;
	}
	for(int i=fuck.size()-1;i>=0;--i)
	for(int j=fuck.size()-1;j>=0;--j) {
		int u=fuck[i],v=fuck[j];
		hh[i][j]=0;
		for(int L=min(len[u],len[v]);L>=1;--L) {
			bool flag=1;
			for(int k=1;k<=L;++k) {
				if(S[u][len[u]-L+k-1]!=S[v][k-1]) {
					flag=0;
					break;
				}
			}
			if(flag) {
				hh[i][j]=L;
				break;
			}
		}
	}
	for(int i=1;i<=Q;++i) {

		int u=read(),v=read();
		if(len[u]<=block||len[v]<=block) {
			int ans=0;
			for(int L=min(len[u],len[v]);L>=0;--L) {
				bool flag=1;
				for(int k=1;k<=L;++k) {
					if(S[u][len[u]-L+k-1]!=S[v][k-1]) {
						flag=0;
						break;
					}
				}
				if(flag) {
					printf("%d\n",L);
					break;
				}
			}
		}
		else printf("%d\n",hh[bel[u]][bel[v]]);
	}
	return 0;
}
