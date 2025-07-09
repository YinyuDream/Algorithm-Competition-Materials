#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T;
ll n;
int num[21],top;
int main(){
    cin>>T;
    while(T--){
        top=0;
        cin>>n;
        while(n){
            num[++top]=n%10;
            n/=10;
        }
        if(num[1]==9||num[top]!=1){
            cout<<"NO"<<endl;
            continue;
        }
        bool flag=true;
        for(int i=2;i<top;i++)
            if(num[i]==0)
                flag=false;
        cout<<(flag?"YES":"NO")<<endl;
    }
    return 0;
}