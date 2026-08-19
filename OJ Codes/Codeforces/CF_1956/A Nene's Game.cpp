#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,k,q;
int a[maxn];
int main(){
    cin>>T;
    while(T--){
        cin>>k>>q;
        for(int i=1;i<=k;i++)
            cin>>a[i];
        for(int i=1;i<=q;i++){
            int num;
            cin>>num;
            cout<<min(a[1]-1,num)<<" ";
        }
        cout<<endl;
    }
    return 0;
}