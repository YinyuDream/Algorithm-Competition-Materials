#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int T,n,cnt;
int ans_i[maxn],ans_j[maxn];
struct node{
	int id,val;
}a[maxn];
bool operator <(node a, node b)
{
	return a.val>b.val;
}
void trans(node &x,node y)
{
	if(x.val%y.val==0){
		x.val/=y.val;
	}else{
		x.val/=y.val;
		x.val++;
	}
}
int main(){
	cin>>T;
	while(T--){
		cnt=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			a[i].id=i;
			cin>>a[i].val;
		}
		sort(a+1,a+n+1);
		if(a[1].val==a[n].val){
			cout<<0<<endl;
			continue;
		}else if(a[n].val==1){
			cout<<-1<<endl;
			continue;
		}else{
			while(a[1].val!=a[n].val){
				trans(a[1],a[n]);
				ans_i[++cnt]=a[1].id;
				ans_j[cnt]=a[n].id;
				sort(a+1,a+n+1);
			}
			cout<<cnt<<endl;
			for(int i=1;i<=cnt;i++){
				cout<<ans_i[i]<<" "<<ans_j[i]<<endl;
			}
		}
	}
	return 0;
}