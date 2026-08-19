#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int n;
struct node{
    ll stu,cor,val,eth;
}a[maxn];
map<pair<ll,ll>,ll>mp_1;
map<pair<ll,ll>,ll>mp_2;
map<ll,vector<node>>mp_cor;
map<ll,vector<node>>mp_stu;
bool cmp(node u,node v)
{
    if(u.cor!=v.cor)return u.cor<v.cor;
    else return u.val>v.val;
}
bool cmp2(node u,node v)
{
    if(u.eth!=v.eth)return u.eth<v.eth;
    else return u.stu<v.stu;
}
bool cmp3(node u,node v)
{
    return u.cor<v.cor;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i].stu>>a[i].cor>>a[i].val;
    sort(a+1,a+n+1,cmp);
    int now=0;
    for(int i=1;i<=n;i++){
        if(a[i].cor!=a[i-1].cor){
            now=1;
            a[i].eth=1;
            now++;
            continue;
        }
        if(a[i].val==a[i-1].val)
            a[i].eth=a[i-1].eth;
        else a[i].eth=a[i-1].eth+1;
        now++;
    }
    for(int i=1;i<=n;i++){
        mp_1.insert(make_pair(make_pair(a[i].stu,a[i].cor),a[i].val));
        mp_2.insert(make_pair(make_pair(a[i].stu,a[i].cor),a[i].eth));
        if(mp_cor.find(a[i].cor)==mp_cor.end()){
            vector<node> vec(1,{a[i].stu,a[i].cor,a[i].val,a[i].eth});
            mp_cor.insert(make_pair(a[i].cor,vec));
        }else{
            mp_cor[a[i].cor].push_back({a[i].stu,a[i].cor,a[i].val,a[i].eth});
        }
        if(mp_stu.find(a[i].stu)==mp_stu.end()){
            vector<node> vec(1,{a[i].stu,a[i].cor,a[i].val,a[i].eth});
            mp_stu.insert(make_pair(a[i].stu,vec));
        }else{
            mp_stu[a[i].stu].push_back({a[i].stu,a[i].cor,a[i].val,a[i].eth});
        }
    }
    for(auto &i:mp_cor){
        std::vector<node> &values = i.second;
        sort(values.begin(), values.end(),cmp2);
    }
    for(auto &i:mp_stu){
        std::vector<node> &values = i.second;
        sort(values.begin(), values.end(),cmp3);
    }
    string s;
    while(true){
        cin>>s;
        if(s=="query1"){
            ll stu,cor;
            cin>>stu>>cor;
            cout<<mp_1[make_pair(stu,cor)]<<endl;
        }
        if(s=="query2"){
            ll stu,cor;
            cin>>stu>>cor;
            cout<<mp_2[make_pair(stu,cor)]<<endl;
        }
        if(s=="query3"){
            ll cor;
            cin>>cor;
            for(auto i:mp_cor[cor])
                cout<<i.stu<<" "<<i.val<<" "<<i.eth<<endl;  
        }
        if(s=="query4"){
            ll stu;
            cin>>stu;
            for(auto i:mp_stu[stu])
                cout<<i.cor<<" "<<i.val<<" "<<i.eth<<endl; 
        }
        if(s=="END"){
            cout<<"OK";
            break;
        }
    }
    return 0;
}