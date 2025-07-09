/*
Farmer John 有太多的工作要做啊！！！！！！！！为了让农场高效运转，他必须靠他的工作赚钱，每项工作花一个单位时间。 他的工作日从0时刻开始，有
1000000000个单位时间（！）。在任一时刻，他都可以选择编号1~N的N(1 <= N <= 100000)项工作中的任意一项工作来完成。 因为他在每个单位时间里只能做一个工
作，而每项工作又有一个截止日期，所以他很难有时间完成所有N个工作，虽然还是有可能。 对于第i个工作，有一个截止时间D_i(1 <= D_i <= 1000000000)，如果他可
以完成这个工作，那么他可以获利P_i( 1<=P_i<=1000000000 ). 在给定的工作利润和截止时间下，FJ能够获得的利润最大为多少呢？答案可能会超过32位整型。
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n;
struct node{
    int d,p;
}a[maxn];
bool cmp(node a,node b)
{
    return a.p!=b.p?a.p>b.p:a.d>b.d;
}
unordered_map<int,pair<bool,int> > book;
long long ans;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i].d>>a[i].p;
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++){
        if(book[a[i].d].first==false){
            ans+=a[i].p;
            book[a[i].d].first=true;
            book[a[i].d].second=a[i].d-1;
        }else{
            int origin=a[i].d;
            while(book[a[i].d].first==true&&a[i].d){
                a[i].d=book[a[i].d].second;
            }
            if(a[i].d>0){
                ans+=a[i].p;
                book[a[i].d].first=true;
                book[a[i].d].second=a[i].d-1;
            }
            book[origin].second=a[i].d;
        }
    }
    cout<<ans;
    return 0;
}