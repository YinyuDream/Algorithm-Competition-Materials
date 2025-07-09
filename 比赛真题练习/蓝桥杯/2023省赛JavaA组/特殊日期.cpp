#include<bits/stdc++.h>
using namespace std;
int yy=1900,mm=1,dd=1,ans;
int num(int x)
{
    int t=0;
    while(x){
        t+=x%10;
        x/=10;
    }
    return t;
}
bool check(int y,int m,int d)
{
    return num(y)==num(m)+num(d);
}
bool is(int y)
{
    if(y%400==0)return true;
    if(y%4==0&&y%100!=0)return true;
    return false;
}
int m[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main(){
    while(yy!=10000){
        if(check(yy,mm,dd))ans++;
        if(dd==m[mm]+(mm==2&&is(yy))){
            dd=1;
            mm++;
            if(mm==13)yy++,mm=1;
        }else{
            dd++;
        }
    }
    cout<<ans<<endl;
    return 0;
}