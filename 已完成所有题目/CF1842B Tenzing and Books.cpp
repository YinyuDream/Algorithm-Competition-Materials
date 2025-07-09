#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int T,n,x,top1,top2,top3;
int a[maxn],b[maxn],c[maxn];
int bit(int num,int pos)
{
	return (num>>(pos-1))&1;
}
int main(){
	cin>>T;
	while(T--){
		cin>>n>>x;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<=n;i++)
			cin>>b[i];
		for(int i=1;i<=n;i++)
			cin>>c[i];
		top1=top2=top3=n;
		for(int i=1;i<=30;i++){
			if(bit(x,i)==0){
				for(int j=1;j<=n;j++){
					if(bit(a[j],i)==1){
						top1=min(top1,j-1);
						break;
					}
				}
				for(int j=1;j<=n;j++){
					if(bit(b[j],i)==1){
						top2=min(top2,j-1);
						break;
					}
				}
				for(int j=1;j<=n;j++){
					if(bit(c[j],i)==1){
						top3=min(top3,j-1);
						break;
					}
				}
			}
		}
		int t=0;
		for(int j=1;j<=top1;j++){
			t|=a[j];
		}
		for(int j=1;j<=top2;j++){
			t|=b[j];
		}
		for(int j=1;j<=top3;j++){
			t|=c[j];
		}
		if(t==x)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}