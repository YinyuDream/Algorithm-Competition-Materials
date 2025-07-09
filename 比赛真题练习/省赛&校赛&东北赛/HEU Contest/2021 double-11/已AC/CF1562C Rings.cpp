#include<bits/stdc++.h>
using namespace std;
const int maxn=2e4+10;
int T,n;
int a[maxn];
int input()
{
	char ch=getchar();
	while(ch!='1'&&ch!='0')
		ch=getchar();
	return ch-'0';
}
int gnum(int l,int r)
{
	int num=0;
	for(int i=r,ls=0;i>=l;i--)
	{
		num+=a[i]*(1<<ls);
		ls++;
	}
	return num;
}
int get_pos()
{
	for(int i=n-1;i>=1;i--)
		if(a[i]==1&&a[i+1]==0)
			return i;
	return 0;	
}
int main(){
	scanf("%d",&T);
	while(T--){
		int book0=0,book1=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			a[i]=input();
			if(a[i])book1++;
			else book0++;
		}
		int pos=get_pos();
		if(pos>=n/2)
			printf("%d %d %d %d\n",1,pos+1,1,pos);
		else if(pos>0)
			printf("%d %d %d %d\n",pos+1,n,pos+2,n);
		else{
			if(book0&&book1)
				printf("%d %d %d %d\n",1,n,2,n);
			else if(book0&&!book1)
				printf("%d %d %d %d\n",1,n,2,n);
			else
				printf("%d %d %d %d\n",1,n-1,2,n);
			
		}
	}
	return 0;
}