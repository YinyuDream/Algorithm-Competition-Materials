#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n;
int a[maxn];
int main(){
    cin>>T;
    while(T--){
        set<int>st;
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<=n;i++)
            st.insert(a[i]);
        if(st.size()==1){
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl;
        if(st.size()>=3){
            cout<<"R";
            for(int i=2;i<=n;i++)
                cout<<"B";
            cout<<endl;
        }else{
            if(a[1]==a[2])
                cout<<"R";
            else
                cout<<"RR";
            for(int i=2+(a[1]!=a[2]);i<=n;i++)
                cout<<"B";
            cout<<endl;
        }
    }
    return 0;
}