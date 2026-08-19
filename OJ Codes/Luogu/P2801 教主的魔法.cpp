#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn=1e3+10;
int n,q;
int left[maxn],right[maxn],pos[maxn*maxn],lazy[maxn];
struct node{
	int id,num;
}a[maxn*maxn];
bool cmp(node x,node y){
	return x.num<y.num;
}
void ycl()
{
	int t=sqrt(n);
	for(int i=1;i<=t;i++)
	left[i]=(i-1)*t+1,right[i]=i*t;
	if(right[t]!=n)
	t++,left[t]=right[t-1]+1,right[t]=n;
	for(int i=1;i<=t;i++){
		for(int j=left[i];j<=right[i];j++)
			pos[j]=i;
		sort(a+left[i],a+right[i]+1,cmp);
	}
}
void update(int l,int r,int c)
{
	if(pos[l]==pos[r]){
		for(int i=left[pos[l]];i<=right[pos[l]];i++)
			if(a[i].id>=l&&a[i].id<=r)
				a[i].num+=c;
		sort(a+left[pos[l]],a+right[pos[r]]+1,cmp);
	}else{
		for(int i=pos[l]+1;i<=pos[r]-1;i++)
			lazy[i]+=c;
		for(int i=left[pos[l]];i<=right[pos[l]];i++)
			if(a[i].id>=l&&a[i].id<=r)
				a[i].num+=c;
		for(int i=left[pos[r]];i<=right[pos[r]];i++)
			if(a[i].id>=l&&a[i].id<=r)
				a[i].num+=c;
		sort(a+left[pos[l]],a+right[pos[l]]+1,cmp);
		sort(a+left[pos[r]],a+right[pos[r]]+1,cmp);
	}
}
int query(int l,int r,int c)
{
	int cnt=0;
	if(pos[l]==pos[r]){
		for(int i=left[pos[l]];i<=right[pos[r]];i++)
			if(a[i].num+lazy[pos[l]]>=c&&a[i].id>=l&&a[i].id<=r)
				cnt++;
	}else{
		for(int i=pos[l]+1;i<=pos[r]-1;i++){
			node x;
			x.num=c-lazy[i];
			int s=lower_bound(a+left[i],a+right[i]+1,x,cmp)-a;
			cnt+=right[i]-s+1;
		}
		for(int i=left[pos[l]];i<=right[pos[l]];i++)
			if(a[i].num+lazy[pos[l]]>=c&&a[i].id>=l&&a[i].id<=r)
				cnt++;
		for(int i=left[pos[r]];i<=right[pos[r]];i++)
			if(a[i].num+lazy[pos[r]]>=c&&a[i].id>=l&&a[i].id<=r)
				cnt++;
	}
	return cnt;
}
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i].num),a[i].id=i;
	ycl();
	for(int i=1,l,r,c;i<=q;i++){
		char ch;
		scanf(" %c %d%d%d",&ch,&l,&r,&c);
		if(ch=='M')update(l,r,c);
		else printf("%d\n",query(l,r,c));
	}
	return 0;
}
