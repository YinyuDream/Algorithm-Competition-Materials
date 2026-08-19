#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n;
int a[maxn],b[maxn],top;
bool check(){
    for(int i=2;i<=top;i++)
        if(b[i-1]>b[i])
            return false;
    return true;
}
int main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        bool flag=0;
        for(int i=1;i<=n+1;i++){
            top=0;
            for(int j=1;j<i;j++){
                if(a[j]<10)
                    b[++top]=a[j];
                else{
                    b[++top]=a[j]/10;
                    b[++top]=a[j]%10;
                }
            }
            for(int j=i;j<=n;j++)
                b[++top]=a[j];
            if(check())
                flag=1;
        }
        if(flag)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}