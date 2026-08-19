#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct sss{
	int value;
	int num;
}k[2000000];
int v[2000000];
int num[2000000];
bool cmp(struct sss a,struct sss b){
	if(a.value<b.value)return 1;
	else return 0;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&(k[i].value));
		k[i].num=i;
	}
	sort(&k[1],&k[n+1],cmp);
	for(int i=1;i<=n;i++){
		v[i]=k[i].value;
		num[i]=k[i].num;
	}
	int l=1;
	int r=n;
	while(1){
		if(l==r){
			cout<<num[l];
			return 0;
		}
		else
		{
			int mid = (k[l].value+k[r].value)/2;
			int pos =upper_bound(v+l,v+r+1,mid)-v;
			int Toright =pos-l;
			int Toleft = r-pos+1;
			if(Toleft>Toright){
				l++;
			}
			else
				r--;
		}
	}
}