#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int T,n,m,k,ka,kb,flag;
int a[maxn],b[maxn],book_a[maxn],book_b[maxn];
int main(){
	cin>>T;
	while(T--){
		cin>>n>>m>>k;
        ka=kb=k/2;
        flag=1;
        for(int i=1;i<=k;i++)
            book_a[i]=book_b[i]=0;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<=m;i++)
            cin>>b[i];
        sort(a+1,a+n+1);
        sort(b+1,b+m+1);
        n=unique(a+1,a+n+1)-a-1;
        m=unique(b+1,b+m+1)-b-1;
        for(int i=1;i<=n;i++)
            if(a[i]<=k)
                book_a[a[i]]++;
        for(int i=1;i<=m;i++)
            if(b[i]<=k)
                book_b[b[i]]++;
        for(int i=1;i<=k;i++)
            if(book_a[i]==0&&book_b[i]==0){
                flag=0;
            }else if(book_a[i]==1&&book_b[i]==0){
                ka--;
            }else if(book_a[i]==0&&book_b[i]==1){
                kb--;
            }
        if(ka<0||kb<0)flag=0;
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
	}
	return 0;
}