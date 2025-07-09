#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n;
int a[maxn],b[maxn];
char s[maxn];
int main(){
    cin>>T;
    while(T--){
        cin>>(s+1);
        n=strlen(s+1);
        for(int i=1;i<=n;i++)
            a[i]=s[i]-'0';
        cin>>(s+1);
        for(int i=1;i<=n;i++)
            b[i]=s[i]-'0';
        for(int i=1;i<=n;i++){
            if(a[i]!=b[i]){
                if(a[i]<b[i])
                    swap(a[i],b[i]);
                for(int j=i+1;j<=n;j++)
                    if(a[j]>b[j])
                        swap(a[j],b[j]);
                break;
            }
        }
        for(int i=1;i<=n;i++)
            cout<<a[i];
        cout<<endl;
        for(int i=1;i<=n;i++)
            cout<<b[i];
        cout<<endl;
    }
    return 0;
}