#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int T,n,q;
int a[maxn],book[maxn],min_l[maxn];
int main(){
	cin>>T;
	while(T--){
		cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            book[i]=0;
            min_l[i]=0;
        }
        for(int i=1;i<n;i++)
            if(a[i]!=a[i+1])
                book[i]=1;
        for(int i=1,now=0;i<=n;i++){
            
            min_l[i]=now;
            if(book[i]==1){
                now=i;
            }
        }
        cin>>q;
        for(int i=1,l,r;i<=q;i++){
            cin>>l>>r;
            if(min_l[r]>=l&&min_l[r]<r){
                cout<<min_l[r]<<" "<<min_l[r]+1<<endl;
            }else{
                cout<<-1<<" "<<-1<<endl;
            }
        }
            
	}
	return 0;
}