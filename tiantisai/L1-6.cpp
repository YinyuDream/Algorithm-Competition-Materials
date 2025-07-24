#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    while(m--){
        int opt;
        cin>>opt;
        if(opt==1){
            int l;
            cin>>l;
            vector<int> v(l+1);
            for(int i=1;i<=l;i++){
                cin>>v[i];
            }
            int t;
            cin>>t;
            vector<int> h(t+1);
            for(int i=1;i<=t;i++){
                cin>>h[i];
            }
            for(int i=1;i+l-1<=n;i++){
                bool find=true;
                for(int j=1;j<=l;j++){
                    if(a[i+j-1]!=v[j]){
                        find=false;
                        break;
                    }
                }
                if(find==true){
                    vector<int> a_new;
                    a_new.push_back(0);
                    for(int j=1;j<i;j++){
                        a_new.push_back(a[j]);
                    }
                    for(int j=1;j<=t;j++){
                        a_new.push_back(h[j]);
                    }
                    for(int j=i+l;j<=n;j++){
                        a_new.push_back(a[j]);
                    }
                    swap(a,a_new);
                    n=a.size()-1;
                    break;
                }
            }
        }else if(opt==2){
            vector<int> a_new;
            a_new.push_back(0);
            for(int i=1;i<n;i++){
                a_new.push_back(a[i]);
                if((a[i]+a[i+1])%2==0){
                    a_new.push_back((a[i]+a[i+1])/2);
                }
            }
            a_new.push_back(a[n]);
            swap(a,a_new);
            n=a.size()-1;
        }else{
            int l,r;
            cin>>l>>r;
            for(int i=l;i<=r-(i-l);i++){
                swap(a[i],a[r-(i-l)]);
            }
        }
    }
    for(int i=1;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<a[n];
}