#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,q,ans,first_b;
int cnt_a[maxn],cnt_b[maxn];
char s[maxn];
long long to_num(string sm){
    long long num=0;
    for(int i=0;i<sm.size();i++){
        num+=(sm[i]-'0')*(1<<(sm.size()-i-1));
    }
    return num;
}
int main(){
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>s[i];
    for(int i=1;i<=n;i++){
        if(s[i]=='A'){
            cnt_a[i]++;
        }else{
            if(!first_b)
                first_b=i;
            cnt_b[i]++;
        }
    }
    for(int i=1;i<=n;i++){
        cnt_a[i]+=cnt_a[i-1];
    }
    for(int i=first_b,sign=-1;i<=n;i++){
        if(cnt_b[i]==1&&cnt_a==0)
            sign=-sign;
        cnt_b[i]=cnt_b[i]*sign+cnt_b[i-1];
    }
    for(int i=1,l,r,real_l,real_r;i<=q;i++){
        string num;
        cin>>l>>r>>num;
        real_l=(ans|l)%n+1,real_r=(ans|r)%n+1;
        if(real_l>real_r)swap(real_l,real_r);
        long long dec_num=to_num(num);
        for(int i=1;i<=n;i++)
            cout<<cnt_b[i]<<"dw";
        puts("");
    }
    return 0;
}