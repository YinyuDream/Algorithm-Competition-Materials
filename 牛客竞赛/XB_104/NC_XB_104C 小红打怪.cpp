#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    int l=0,r=*max_element(a.begin(),a.end());
    auto check=[&](int x){
        auto b=a;
        for(int i=0;i<n;i++){
            b[i]=max(b[i]-x,0);
        }
        int cnt_1=x,cnt_2=x;
        for(int i=0;i<n-1;i++){
            if(b[i]>0&&b[i+1]>0){
                int mn=min(b[i],b[i+1]);
                mn=min(mn,cnt_2);
                b[i]-=mn;
                b[i+1]-=mn;
                cnt_2-=mn;
                if(cnt_2==0){
                    break;
                }
            }
        }
        cnt_1+=cnt_2;
        for(int i=0;i<n;i++){
            if(cnt_1>=b[i]){
                cnt_1-=b[i];
                b[i]=0;
            }else{
                b[i]-=cnt_1;
                cnt_1=0;
            }
        }
        for(int i=0;i<n;i++){
            if(b[i]>0){
                return false;
            }
        }
        return true;
    };
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)){
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    cout<<l<<endl;
    return 0;
}