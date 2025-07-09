#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<string> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    int x=0,y=0;
    for(int i=0;i<n;i++){
        bool flag=false;
        for(int j=0;j<m;j++){
            if(v[i][j]=='x'){
                flag=true;
                if(!x)y++;
            }
        }
        x+=flag;
    }
    int gcd=__gcd(x,y);
    x/=gcd,y/=gcd;
    for(int i=1;i<=x;i++){
        for(int j=1;j<=y;j++)
            cout<<"x";
        cout<<endl;
    }
}