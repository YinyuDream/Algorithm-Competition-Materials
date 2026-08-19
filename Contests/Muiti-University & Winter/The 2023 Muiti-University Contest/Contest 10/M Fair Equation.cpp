#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll num[600000];
ll ans[600000];
int main(){
    ll a;
    ll b;
    ll c;
    char s;
    cin>>a>>s>>b>>s>>c;
    if(a+b==c){
        cout<<"Yes"<<endl;
        cout<<a<<" + "<<b<<" = "<<c;
        return 0;
    }
    ll k=log10(a)+1;
    for(int i=0;i<=k;i++){
        ll now;
        ll head=a/pow(10,k-i);
        ll tail=a-head*pow(10,k-i);
        for(int j=0;j<=9;j++){
            if(i==0&&j==0)continue;
            else
            {
                now=head*pow(10,k-i+1)+j*pow(10,k-i)+tail;
                if(now+b==c){
                        cout<<"Yes"<<endl;
                        cout<<now<<" + "<<b<<" = "<<c;
                        return 0;
                }
            }
        }
    }
     k=log10(b)+1;
    for(int i=0;i<=k;i++){
        ll now;
        ll head=b/pow(10,k-i);
        ll tail=b-head*pow(10,k-i);
    //  cout<<tail<<endl;
        for(int j=0;j<=9;j++){
            if(i==0&&j==0)continue;
            else
            {
                now=head*pow(10,k-i+1)+j*pow(10,k-i)+tail;
                if(now+a==c){
                    cout<<"Yes"<<endl;
                    cout<<a<<" + "<<now<<" = "<<c;
                    return 0;
                }
            }
        }
    }
    k=log10(c)+1;
    for(int i=0;i<=k;i++){
        ll now;
        ll head=c/pow(10,k-i);
        ll tail=c-head*pow(10,k-i);
        for(int j=0;j<=9;j++){
            if(i==0&&j==0)continue;
            else
            {
                now=head*pow(10,k-i+1)+j*pow(10,k-i)+tail;
                if(a+b==now){
                    cout<<"Yes"<<endl;
                    cout<<a<<" + "<<b<<" = "<<now;
                    return 0;
                }
            }
        }
    }
    cout<<"No";
}