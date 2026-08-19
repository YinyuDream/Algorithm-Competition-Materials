#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int n;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        cout<<(i%3==0?'x':'o');
    return 0;
}