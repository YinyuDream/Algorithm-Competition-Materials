#include<bits/stdc++.h>
using namespace std;
vector<int> month={0,31,28,31,30,31,30,31,31,30,31,30,31};
int to_int(string s){
    int yy=stoi(s.substr(0,4));
    int mm=stoi(s.substr(5,2));
    int dd=stoi(s.substr(8,2));
    int ans=0;
    ans=ans+yy*365;
    for(int i=1;i<mm;i++){
        ans=ans+month[i];
    }
    ans=ans+dd;
    return ans;
}
string to_str(int x){
    int yy=(x-1)/365;
    if(x%365==0){
        x=365;
    }else{
        x=x%365;
    }
    int mm=1;
    while(x>month[mm]){
        x=x-month[mm];
        mm++;
    }
    int dd=x;
    string yy_str=to_string(yy);
    while(yy_str.size()<4) yy_str="0"+yy_str;
    string mm_str=to_string(mm);
    while(mm_str.size()<2) mm_str="0"+mm_str;
    string dd_str=to_string(dd);
    while(dd_str.size()<2) dd_str="0"+dd_str;
    string str=yy_str+'-'+mm_str+'-'+dd_str;
    return str;
}
int main(){
    int lim=to_int("6005-12-31"),from=-1;
    vector<int> book(lim+1,1);
    book[0]=0;
    int n,y,d;
    cin>>n>>y>>d;
    for(int i=1;i<=n;i++){
        string st,ed;
        cin>>st>>ed;
        int st_int=to_int(st);
        int ed_int=to_int(ed);
        if(i==n){
            from=ed_int+1;
        }
        for(int j=st_int;j<=ed_int;j++){
            book[j]=0;
        }
    }
    for(int i=1;i<=lim;i++){
        book[i]+=book[i-1];
    }
    for(int i=max(from,y*365+1);i<=lim;i++){
        int r=i-1,l=r-365+1;
        bool can=true;
        for(int j=1;j<=y;j++){
            if(book[r]-book[l-1]<d){
                can=false;
                break;
            }
            r=r-365;
            l=l-365;
        }
        if(can){
            cout<<to_str(i)<<endl;
            return 0;
        }
    }
    return 0;
}