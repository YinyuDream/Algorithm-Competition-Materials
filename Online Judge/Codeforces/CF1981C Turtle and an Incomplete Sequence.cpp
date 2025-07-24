#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n;
int a[maxn];
vector<int>pos;
bool all(){
    for(int i=1;i<=n;i++)
        if(a[i]!=-1)
            return true;
    return false;
}
void init(){
    for(int i=1;i<=n;i++){
        if(a[i]!=-1){
            for(int j=i-1;j>=1;j--){
                if(a[j+1]!=1){
                    a[j]=a[j+1]/2;
                }else{
                    a[j]=a[j+1]*2;
                }
            }
            break;
        }
    }
    for(int i=n;i;i--){
        if(a[i]!=-1){
            for(int j=i+1;j<=n;j++){
                if(a[j-1]!=1){
                    a[j]=a[j-1]/2;
                }else{
                    a[j]=a[j-1]*2;
                }
            }
            break;
        }
    }
    for(int i=1;i<=n;i++)
        if(a[i]!=-1)
            pos.push_back(i);
}
int work(int l,int r)
{
    if(r==l+1)
        return a[l]/2==a[r]||a[r]/2==a[l];
    for(int i=l+1;i<r;i++){
        if(a[i-1]!=1){
            a[i]=a[i-1]/2;
        }else{
            a[i]=a[i-1]*2;
        }
    }
    if(a[r-1]/2==a[r]||a[r]/2==a[r-1])
        return 1;
    int can=0;
    for(int i=r-1;i>l;i--){
        if(a[i+1]!=1){
            a[i]=a[i+1]/2;
        }else{
            a[i]=a[i+1]*2;
        }
        if(a[i-1]/2==a[i]||a[i]/2==a[i-1]){
            can=1;
            break;
        }
    }
    return can;
}
int main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        if(!all()){
            for(int i=1;i<=n;i++)
                cout<<(i&1)+1<<" ";
            cout<<endl;
            continue;
        }
        pos.clear();
        init();
        bool can=true;
        for(auto i=pos.begin();i!=prev(pos.end());i++){
            int l=*i,r=*next(i);
            can&=work(l,r);
        }
        if(can){
            for(int i=1;i<=n;i++)
                cout<<a[i]<<" ";
            cout<<endl;
        }else{
            cout<<-1<<endl;
        }
    }
    return 0;
}