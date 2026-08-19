#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int T,n,val,cnt,num,pos,val_2;
int a[maxn];
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		val=a[1];
		for(int i=2;i<=n;i++)
			val&=a[i];
		val_2=a[1];
		for(int i=1;i<=n;i++){
			val_2&=a[i];
			if(val_2==val){
				pos=i;
				break;
			}
		}
		num=a[n];
		cnt=0;
		for(int i=n-1;i>=pos;i--){
			if(num==0){
				cnt++;
				num=a[i];
			}
			num&=a[i];
		}
		cout<<cnt+1<<endl;
	} 
	return 0;
}