#include<bits/stdc++.h>
using namespace std;
int month[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
bool is_leap(int x){
    return x%4==0&&x%100!=0||x%400==0;
}
tuple<int,int,int> next_day(int yy,int mm,int dd){
    dd++;
    if(dd>month[mm]+(mm==2&&is_leap(yy))){
        dd=1;
        mm++;
        if(mm>12){
            mm=1;
            yy++;
        }
    }
    return make_tuple(yy,mm,dd);
}
int main(){
    int ans=0;
    int yy=1901,mm=1,dd=1,week=2;
    while(yy!=2025||mm!=1||dd!=1){
        if(dd%10==1&&week==1){
            ans++;
        }
        tie(yy,mm,dd)=next_day(yy,mm,dd);
        week++;
        if(week>7){
            week=1;
        }
    }
    cout<<ans<<endl;
    return 0;
}