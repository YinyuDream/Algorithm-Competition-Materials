#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n;
int a[maxn],b[maxn];
bool work(int pos)
{
    int top=0;
    for(int i=pos+1;i<=n;i++){
        b[++top]=a[i];
    }
    for(int i=1;i<=pos;i++){
        b[++top]=a[i];
    }
    for(int i=1;i<n;i++)
        if(b[i]>b[i+1]){
            return false;
        }
    return true;
}
int main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        bool flag=0;
        for(int i=1;i<=n;i++){
            if(work(i)){
                flag=1;
                cout<<"Yes"<<endl;
                break;
            }
        }
        if(!flag)
            cout<<"No"<<endl;
    }
    return 0;
}