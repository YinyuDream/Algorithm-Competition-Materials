#include<bits/stdc++.h>
using namespace std;
int x,y;
int main(){
    cin>>x>>y;
    if(x==0&&y==0)cout<<4;
    else if(x==0&&y==1)cout<<4;
    else if(x==0&&y==2)cout<<6;
    else if(x==1&&y==0)cout<<3;
    else if(x==1&&y==1)cout<<3;
    else if(x==1&&y==2)cout<<4;
    else if(x==2)cout<<2;
    return 0;
}