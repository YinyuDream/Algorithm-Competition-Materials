#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n,k;
int a[maxn],mx[maxn];
int main(){
    cin>>T;
    while(T--){
        cin>>n>>k;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<=n;i++)
            mx[i]=max(mx[i-1],a[i]);
        int ans=0;
        for(int i=2;i<=n;i++)
            if(mx[i]==a[k])
                ans++;
        if(mx[k-1]<a[k]){
            swap(a[1],a[k]);
            for(int j=1;j<=n;j++)
                mx[j]=max(mx[j-1],a[j]);
            int num=0;
            for(int i=2;i<=n;i++)
                if(mx[i]==a[1])
                    num++;
            ans=max(ans,num);
            cout<<ans<<endl;
        }else{
            int pos=0;
            for(int i=1;i<k;i++){
                if(a[i]>a[k]){
                    pos=i;
                    break;
                }
            }
            swap(a[1],a[k]);
            for(int j=1;j<=n;j++)
                mx[j]=max(mx[j-1],a[j]);
            int num=0;
            for(int j=2;j<=n;j++)
                if(mx[j]==a[1])
                    num++;
            ans=max(ans,num);
            swap(a[1],a[k]);
            
            swap(a[pos],a[k]);
            for(int j=1;j<=n;j++)
                mx[j]=max(mx[j-1],a[j]);
            num=0;
            for(int j=2;j<=n;j++)
                if(mx[j]==a[pos])
                    num++;
            ans=max(ans,num);
            cout<<ans<<endl;
        }
    }
    return 0;
}