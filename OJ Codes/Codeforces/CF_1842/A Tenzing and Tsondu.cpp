#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+10;
int T,n,m,cnt,t1,t2;
int a[maxn],b[maxn];
int *find_exterme(int *start,int *end,int opt)
{
	int *pos;
	if(opt==1){
		int mx=0;
		for(int i=0;i+start<=end;i++){
			if(mx<*(start+i)){
				mx=*(start+i);
				pos=i+start;
			}
		}
	}else{
		int mn=0x7f7f7f7f;
		for(int i=0;i+start<=end;i++){
			if(mn>*(start+i)&&*(start+i)>0){
				mn=*(start+i);
				pos=i+start;
			}
		}
	}
	return pos;
}
int main(){
	cin>>T;
	while(T--){
		cin>>n>>m;
		t1=n,t2=m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=m;i++){
			cin>>b[i];
		}
		cnt=1;
		while(n>0&&m>0){
			int *x=0,*y=0;
			if(cnt%2==1){
				x=find_exterme(a+1,a+t1,1);
				y=find_exterme(b+1,b+t2,2);
				int delta_1=*x-*y,delta_2=*y-*x;
				if(delta_1>0){
					*x=delta_1;
					*y=0;
					m--;
				}else if(delta_1<0){
					*x=0;
					*y=delta_2;
					n--;
				}else{
					*x=*y=0;
					n--;
					m--;
				}
			}else{
				y=find_exterme(a+1,a+t1,2);
				x=find_exterme(b+1,b+t2,1);
				int delta_1=*x-*y,delta_2=*y-*x;
				if(delta_1>0){
					*x=delta_1;
					*y=0;
					n--;
				}else if(delta_1<0){
					*x=0;
					*y=delta_2;
					m--;
				}else{
					*x=*y=0;
					n--;
					m--;
				}
			}
			cnt++;
		}
		if(n==0&&m==0)cout<<"Draw";
		else if(n==0)cout<<"Tenzing";
		else cout<<"Tsondu";
		cout<<endl;
	}
	return 0;
}