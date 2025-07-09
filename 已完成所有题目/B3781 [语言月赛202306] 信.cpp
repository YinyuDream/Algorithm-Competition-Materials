#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,x,y,a,b,cont_a,cont_b;
long long val,max_val;
int s1[maxn],s2[maxn],m[maxn];
int main(){
	cin>>n>>x>>y>>a>>b;
	for(int i=1;i<=n;i++)
		cin>>s1[i]>>s2[i]>>m[i];
	for(int i=1;i<=n;i++)
		m[i]-=x*s1[i]+y*s2[i];
	for(int i=1;i<=n;i++){
		if(m[i]==0){
			if(cont_a)cont_a=cont_b=0;
			cont_b++;
			if(cont_b>=b){
				val/=2;
			}
		}else{
			if(cont_b)cont_a=cont_b=0;
			val+=m[i];
			if(m[i]>x*s1[i]+y*s2[i])val+=m[i]/2+m[i]%2;
			cont_a++;
			if(cont_a>=a)val*=2;
		}
		max_val=max(max_val,val);
	}
	cout<<max_val<<" "<<val;
	return 0;
}