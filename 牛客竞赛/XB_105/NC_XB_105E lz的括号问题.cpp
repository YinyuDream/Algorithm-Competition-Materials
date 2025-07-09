#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int now=0;
    for(int i=0;i<n*2;i++){
        if(s[i]=='('){
            now++;
        }else{
            now--;
        }
        if(now<0){
            cout<<-1<<endl;
            return 0;
        }
    }
    if(now){
        cout<<-1<<endl;
        return 0;
    }
    for(int i=0;i<n*2;i++){
        if(s[i]=='('){
            now++;
            cout<<n-now<<" ";
        }else{
            now--;
        }
    }
    return 0;
}