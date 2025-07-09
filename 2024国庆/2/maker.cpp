#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("data.in","w",stdout);
    srand(time(0));
    
    int n=100000,m=100000;
    cout<<n<<' '<<m<<endl;
    for(int i=1;i<=n;i++){
        cout<<rand()%2;
    }
    cout<<endl;
    for(int i=1;i<=n;i++){
        cout<<rand()%2;
    }
    cout<<endl;
    for(int i=1;i<=m;i++){
        int l=rand()%n+1,r=rand()%n+1;
        if(l>r) swap(l,r);
        cout<<l<<' '<<r<<endl;
    }
    return 0;
}