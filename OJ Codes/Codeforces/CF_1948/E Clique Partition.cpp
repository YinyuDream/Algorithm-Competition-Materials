#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n,k;
int a[maxn],b[maxn];
int main(){
    cin>>T;
    while(T--){
        cin>>n>>k;
        if(k==2){
            a[1]=2,a[2]=1;
        }else{
            int cnt=0;
            for(int i=k/2+2;i<=k;i++)
                a[++cnt]=i;
            for(int i=1;i<a[1];i++)
                a[++cnt]=i;
        }
        int num=n/k;
        for(int i=k+1;i<=num*k;i++){
            if(i%k!=0)
                a[i]=a[i%k]+i/k*k;
            else
                a[i]=a[k]+(i/k-1)*k;
        }
        int los=n%k;
        if(los){
            if(los==1)
                b[1]=1;
            else if(los==2)
                b[1]=2,b[2]=1;
            else{
                int cnt=0;
                for(int i=los/2+2;i<=los;i++)
                    b[++cnt]=i;
                for(int i=1;i<a[1];i++)
                    b[++cnt]=i;
            }
        }
        for(int i=num*k+1;i<=n;i++)
            a[i]=b[i-num*k]+num*k;
        for(int i=1;i<=n;i++)
            cout<<a[i]<<" ";
        cout<<endl;
        if(n%k!=0)
            num++;
        cout<<num<<endl;
        for(int i=1;i<=n;i++)
            cout<<(i-1)/k+1<<" ";
        cout<<endl;
    }
    return 0;
}