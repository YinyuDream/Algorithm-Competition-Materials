#include<bits/stdc++.h>
#define ll long long
#define mxn 1000003
#define md 1000000007
#define pb push_back
#define mkp make_pair
#define ld long double
#define umap unordered_map
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define rept(i,a,b) for(int i=a;i<b;++i)
#define drep(i,a,b) for(int i=a;i>=b;--i)
#define pq priority_queue
using namespace std;
int t,n,k,c,a[mxn],f[mxn];
bool b[32];
signed main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&k);
		rept(i,0,30)b[i]=0;
		rept(i,1,n)scanf("%d",&a[i]),f[i]=0;
		rept(i,1,n){
			drep(j,29,0)if((a[i]>>j)&1){
				if(b[j]){
					if((f[i]>>j)&1){
						puts("-1");
						goto next;
					}
				}else{
					b[j]=1;
					drep(k,i-1,1)f[k]|=(((f[k+1]>>j)&1)^((a[k]>>j)&1))<<j;
					rep(k,i+1,n)f[k]|=(((f[k-1]>>j)&1)^((a[k-1]>>j)&1))<<j;
				}
				break;
			}
		}
		c=1;
		rept(i,0,30)if(!b[i])c<<=1;
		if(c<k){
			puts("-1");
			continue;
		}
		k--;
		c=0;
		rept(i,0,30)if(!b[i]){
			f[1]|=((k>>c)&1)<<i;
			c++;
		}
		printf("%d ",f[1]);
		rep(i,2,n){
			f[i]=f[i-1]^a[i-1];
			printf("%d ",f[i]);
		}
		puts("");
		next:;
	}
	return 0;
}
