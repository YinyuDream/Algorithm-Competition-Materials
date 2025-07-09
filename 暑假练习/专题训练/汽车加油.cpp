/*
一辆汽车加满油后可行驶n公里。旅途中有若干个加油站。设计一个有效算法，指出应在哪些加油站停靠加油，使沿途加油次数最少。
对于给定的n和k(k <= 1000)个加油站位置，编程计算最少加油次数。
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,k,ans,last;
int a[maxn];
int main(){
    cin>>n>>k;
    for(int i=1;i<=k+1;i++)
        cin>>a[i];
    for(int i=1;i<=k+1;i++){
        if(a[i]>n){
            cout<<"No Solution";
            return 0;
        }
    }
    for(int i=2;i<=k+1;i++)
        a[i]+=a[i-1];
    last=0;
    for(int i=0;i<=k;i++){
        if(a[i+1]-a[last]>n){
            ans++;
            last=i;
        }
    }
    cout<<ans<<endl;
    return 0;
}
