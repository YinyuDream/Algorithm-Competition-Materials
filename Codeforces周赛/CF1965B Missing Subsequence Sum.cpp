#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n,k;
int a[26];
int main(){
    cin>>T;
    while(T--){
        cin>>n>>k;
        a[1]=1;
        for(int i=2;i<=25;i++)
            a[i]=a[i-1]*2;
        a[25]=k+1;
        if(k==1){
            cout<<25<<endl;
            a[1]=3;
            for(int i=1;i<=25;i++)
                cout<<a[i]<<" ";
            cout<<endl;
        }else{
            int mx=-1,lmx=-1;
            for(int i=0;i<=25;i++){
                if((k>>i)&1){
                    lmx=mx;
                    mx=i;
                }
            }
            //cout<<mx<<" "<<lmx<<endl;
            if(lmx!=-1){
                a[mx+1]-=a[lmx+1];
            }else{
                a[mx+1]++;
            }
            cout<<25<<endl;
            for(int i=1;i<=25;i++)
                cout<<a[i]<<" ";
            cout<<endl;
        }
    }
    return 0;
}