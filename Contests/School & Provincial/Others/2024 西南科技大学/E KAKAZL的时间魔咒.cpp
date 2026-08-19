#include<bits/stdc++.h>
using namespace std;
int time(int hh,int mm){
    return hh*60+mm;
}
bool is_palindromic(int hh,int mm){
    return hh%10==mm/10&&hh/10==mm%10;
}
vector<pair<int,int>> st;
int main(){
    for(int i=0;i<24;i++)
        for(int j=0;j<60;j++)
            if(is_palindromic(i,j))
                st.push_back({i,j});
    int T;
    cin>>T;
    while(T--){
        string current_time;
        cin>>current_time;
        int hh=stoi(current_time.substr(0,2));
        int mm=stoi(current_time.substr(3,2));
        auto now=lower_bound(st.begin(),st.end(),make_pair(hh,mm));
        if(now!=st.end()){
            auto [x,y]=*now;
            cout<<setw(2)<<setfill('0')<<x<<":"<<setw(2)<<setfill('0')<<y<<endl;
            cout<<time(x,y)-time(hh,mm)<<endl;
        }else{
            auto [x,y]=st[0];
            cout<<setw(2)<<setfill('0')<<x<<":"<<setw(2)<<setfill('0')<<y<<endl;
            cout<<time(x,y)-time(hh,mm)+1440<<endl;
        }
    }
    return 0;
}