#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=110;
int T,n,k;
int a[maxn],b[maxn];
int main(){
    cin>>T;
    while(T--){
        cin>>n>>k;
        for(int i=0;i<=n;i++){
            if(n-i>k){
                for(int j=i;j<=n-k-1;j++)
                    a[j]=n-j+i;
                a[n-k]=i;
                for(int j=n-k+1;j<=n;j++)
                    a[j]=a[n-k-1]-j+n-k;
                break;
            }
            k-=n-i;
            a[i]=i;
        }
        for(int i=1;i<=n;i++)
            b[i]=a[i]-a[i-1];
        for(int i=1;i<=n;i++)
            cout<<b[i]<<" ";
        cout<<endl;
    }
    return 0;
}