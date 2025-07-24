#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int T,n;
char s[maxn];
set<int> mySet;
bool check(int pos)
{
    return s[pos]=='b'||s[pos]=='c'||s[pos]=='d';
}
int main(){
    cin>>T;
    while(T--){
        mySet.clear();
        cin>>n>>s+1;
        for(int i=1;i<=n;i++){
            if(check(i)&&check(i+1))
                 mySet.insert(i);
        }
        if(check(n))mySet.insert(n);
        for(int i=1;i<=n;i+=2){
            cout<<s[i]<<s[i+1];
            if(mySet.find(i+2)!=mySet.end()){
                cout<<s[i+2];
                if(i!=n-2)cout<<'.';
                i++;
            }else{
                if(i!=n-1)cout<<'.';
            }
        }
        cout<<endl;
    }
    return 0;
}