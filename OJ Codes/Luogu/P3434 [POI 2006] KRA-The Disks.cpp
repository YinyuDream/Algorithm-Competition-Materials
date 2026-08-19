#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,m;
int r[maxn],k[maxn],point;
int top;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&r[i]);
    for(int i=1;i<=m;i++)    
        scanf("%d",&k[i]);
    for(int i=2;i<=n;i++)
    	if(r[i]>r[i-1])
    		r[i]=r[i-1];
    point=n;
    for(int i=1;i<=m;i++)
    {
    	if(r[point]>=k[i]){
    		point--;
    		continue;
    	}
    	while(r[point]<k[i])
    		point--;
    	point--;
    }
    printf("%d",(point+1)>=0?point+1:0);
    return 0;
}