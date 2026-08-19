#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int T,n;
int a[maxn],book[maxn];
int main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++)
            book[i]=a[i]=0;
        a[1]=book[1]=1;
        for(int i=2;i<n;i++){
            if(a[i-1]==0)break;
            if(book[a[i-1]*2%n]==0) a[i]=a[i-1]*2%n;
            else if(book[a[i-1]*3%n]==0) a[i]=a[i-1]*3%n;
            book[a[i]]=1;
        }
        if(a[n-1]==0){
            cout<<-1<<endl;
            continue;
        }
        for(int i=1;i<n;i++)
            cout<<a[i]<<" ";
        cout<<endl;
    }
    return 0;
}