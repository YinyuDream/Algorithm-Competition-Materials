#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
bool is_int=true;
int n;
int num,a[maxn];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    num=a[1];
    for(int i=2;i<=n+1;i++){
        if(is_int){
            if(num==0)cout<<'0';
            else if(num<0)cout<<'-';
            else if(num>0)cout<<'+';
        }else{
            if(num>0||(num==0&&!is_int))cout<<'+';
            else cout<<'-';
        }
        if((num%2+2)%2==1)
            is_int=false;
        if(num>=0)num=num/2+a[i];
        else num=num/2-(num%2!=0)+a[i];
    }
    return 0;
}