#include<cstdio>
#include<cstring>
using namespace std;
int n,len,ans[300],m[300],k;
char a[300];
int main(){
	scanf("%s%d",a,&n);
	len=strlen(a);
	for(int i=0;i<len;i++){
		m[i+1]=a[i]-'0';
	}
	for(int i=1;i<=len;i++){
		int minn=10,minx=i;
		k++;
		for(;i<=n+k;i++){
			if(minn>m[i]){
				minn=m[i];minx=i;
			}
		}
		ans[k]=minn;
		i=minx;
	}
	int i=1;
	while(ans[i]==0&&i<300)i++;
	if(i==300)printf("0");
	for(;i<=len-n;i++)
		printf("%d",ans[i]);
	return 0;
}
