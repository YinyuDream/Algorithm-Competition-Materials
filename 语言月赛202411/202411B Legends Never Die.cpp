#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,k;
    cin>>a>>b>>c>>k;
    cout<<((a+b>=k)?"Yes":"No")<<endl;
    cout<<((a+c>=k)?"Yes":"No")<<endl;
    cout<<((b+c>=k)?"Yes":"No");
    return 0;
}