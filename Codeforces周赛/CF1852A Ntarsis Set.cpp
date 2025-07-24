#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int T,n,k;
int a[maxn];
int main(){
	cin>>T;
	while(T--){
        
		cin>>n>>k;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        if(a[1]>=2){
            cout<<1<<endl;
            continue;
        }
        int lst=1;
        for(int i=2;i<=n;i++){
            int t=(a[i]-lst)/(i-1);
            if(k-t<=0){
                cout<<lst+(i-1)*k<<endl;
                break;
            }else{
                k-=t;
                lst+=a[i]+(i-1)*t;
            }
        }
        //cout<<lst+n*k<<endl;
	}
	return 0;
}