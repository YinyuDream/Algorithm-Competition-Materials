#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int T,n;
long long ans,sum[maxn];
int pos[maxn],top;
struct node{
	int a,b;
}lamp[maxn];
bool cmp(node x,node y)
{
	if(x.a!=y.a)return x.a<y.a;
	else return x.b<y.b;
}
int main(){
	cin>>T;
	while(T--){
		ans=top=0;
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>lamp[i].a>>lamp[i].b;
		sort(lamp+1,lamp+n+1,cmp);
		for(int i=1;i<=n;i++)
			sum[i]=0;
		for(int i=1;i<=n;i++)
			sum[i]=sum[i-1]+lamp[i].b;
		for(int i=0;i<n;i++){
			if(lamp[i+1].a!=lamp[i].a)
				pos[++top]=i+1;
		}
		pos[++top]=n+1;
		/*for(int i=1;i<=n;i++){
			cout<<"ss"<<lamp[i].a<<" "<<lamp[i].b<<endl;
		}
		for(int i=1;i<=n;i++){
			cout<<sum[i]<<endl;
		}*/
		for(int i=2;i<=top;i++)
			if(pos[i]-pos[i-1]<=lamp[pos[i-1]].a)
				ans+=sum[pos[i]-1]-sum[pos[i-1]-1];//,puts("tt");
			else ans+=sum[pos[i]-1]-sum[pos[i]-lamp[pos[i-1]].a-1];//,puts("dw"),printf("%d",pos[i]-lamp[pos[i-1]].a);
		cout<<ans<<endl;
	}
	return 0;
}