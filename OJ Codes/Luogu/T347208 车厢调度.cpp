#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+10;
int n,top_a,top_c;
int a[maxn],b[maxn],c[maxn],pos[maxn];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>b[i];
        a[i]=n-i+1;
        pos[i]=1;
    }
    top_a=n;
    for(int i=1;i<=n;i++){
        if(pos[b[i]]==1){
            while(a[top_a]!=b[i]){
                pos[a[top_a]]=2;
                c[++top_c]=a[top_a--];
            }
            top_a--;
        }else{
            if(c[top_c]!=b[i]){
                cout<<"NO"<<endl;
                return 0;
            }else{
                top_c--;
            }
        }
    }
    cout<<"YES"<<endl;
    return 0;
}