#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,cnt=0;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cnt+=(a[i]!=0);
    }
    cout<<*max_element(a.begin()+1,a.end())+cnt<<endl;
    return 0;
}
