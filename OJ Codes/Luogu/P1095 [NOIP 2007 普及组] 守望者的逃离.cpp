#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int m,s,t,ans=0x7f7f7f7f,dis;//m:initial magic index,s:distance,t:time limit
int b[maxn],a[maxn];//stay for t(s) the min time and the max distance in t(s)
int main(){
	scanf("%d%d%d",&m,&s,&t);
	for(int i=0;i<=t;i++){
		if((m+4*i)/10*60>=s)b[i]=i+(s+59)/60;
		else b[i]=i+(m+4*i)/10+((s-(m+4*i)/10*60)+16)/17;
		if(i+(m+4*i)/10>=t)a[i]=(t-i)*60;
		else a[i]=(m+4*i)/10*60+(t-i-(m+4*i)/10)*17;
	}
	for(int i=0;i<=t;i++)
		ans=min(ans,b[i]),dis=max(dis,a[i]);
	if(ans<=t)printf("Yes\n%d",ans);
	else printf("No\n%d",dis);
	return 0;
}