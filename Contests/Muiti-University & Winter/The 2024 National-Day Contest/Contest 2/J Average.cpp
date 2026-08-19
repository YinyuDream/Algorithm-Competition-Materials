#include<bits/stdc++.h>
using namespace std;
const double eps=1e-9;
int main(){
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    vector<int> a(n+1),b(m+1);
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=m;i++)
        cin>>b[i];
    auto check=[&](vector<int> &num,int len,double avg){
        int sz=num.size();
        vector<double> u(sz);
        for(int i=1;i<sz;i++)
            u[i]=num[i]-avg;
        vector<double> sum(sz),mn(sz);
        for(int i=1;i<sz;i++)
            sum[i]=sum[i-1]+u[i];
        mn[1]=sum[0];
        for(int i=2;i<sz;i++)
               mn[i]=min(mn[i-1],sum[i-1]);
        bool can=false;
        for(int i=len;i<sz;i++){
            if(sum[i]-mn[i-len+1]>=0){
                can=true;
                break;
            }
        }
        return can;
    };
    auto work=[&](vector<int> &num, int lim){
        double l=0,r=*max_element(num.begin(),num.end());
        while(r-l>eps){
            double mid=(l+r)/2;
            if(check(num,lim,mid)){
                l=mid;
            }else{
                r=mid;
            }
        }
        return (l+r)/2;
    };
    cout<<fixed<<setprecision(10);
    cout<<work(a,x)+work(b,y);
    return 0;
}