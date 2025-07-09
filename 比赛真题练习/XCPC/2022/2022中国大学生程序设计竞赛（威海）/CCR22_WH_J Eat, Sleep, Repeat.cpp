#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n,k;
int a[maxn],b[maxn];
ll sum_1,sum_2;
map<int,int>lim;
vector<int>seg;
void work(int down,int up)
{
    int l=lower_bound(a+1,a+n+1,down)-a;
    int r=upper_bound(a+1,a+n+1,up)-a-1;
    if(l>r)return;
    int pos=l;
    for(int i=down;i<=up;i++){
        if(lim.find(i)==lim.end()){
            while(pos<=r){
                b[pos]=i;
                pos++;
            }
            return ;
        }
        for(int j=1;j<=lim[i];j++){
            b[pos]=i;
            pos++;
            if(pos>r)return;
        }
    }
}
int main(){
    cin>>T;
    while(T--){
        lim.clear();
        seg.clear();
        sum_1=sum_2=0;
        cin>>n>>k;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            sum_1+=a[i];
        }
        sort(a+1,a+n+1);
        for(int i=1;i<=k;i++){
            int x,y;
            cin>>x>>y;
            lim[x]=y;
        }
        seg.push_back(-1);
        for(auto i:lim){
            if(i.second==0){
                seg.push_back(i.first);
            }
        }
        seg.push_back(1e9+1);
        for(auto i=seg.begin();i!=seg.end()-1;i++)
            if((*i)+1<=(*next(i))-1)
                work((*i)+1,(*next(i))-1);
        for(int i=1;i<=n;i++)
            sum_2+=b[i];
        if((sum_2-sum_1)&1)cout<<"Pico";
        else cout<<"FuuFuu";
        cout<<endl;
    }
    return 0;
}