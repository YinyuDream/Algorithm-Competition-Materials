#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> generate_gray_code(int n) {
    vector<int> gray_code;
    if (n <= 0) 
        return gray_code;
    gray_code.push_back(0);
    for (int i = 0; i < n; ++i) {
        int size = gray_code.size();
        for (int j = size - 1; j >= 0; --j) 
            gray_code.push_back(gray_code[j] | (1 << i));
    }
    return gray_code;
}
int main(){
    cin>>n;
    vector<int> gray_code = generate_gray_code(n);
    for(int i=1;i<=n;i++){
        int mx=0,val=0,pos=0;
        for(int j=0;j<(1<<(n-i+1))-1;j++){
            cin>>val;
            if(val==n){
                return 0;
            }
            if(val>=mx){
                mx=val;
                pos=j;
            }
            cout<<i<<" "<<i+__builtin_ctz(gray_code[j]^gray_code[j+1])<<endl;
            cout<<flush;
        }
        cin>>val;
        if(val==n){
            return 0;
        }
        if(val>=mx){
            mx=val;
            pos=(1<<(n-i+1))-1;
        }
        cout<<i<<" "<<i+__builtin_ctz(gray_code[(1<<(n-i+1))-1]^gray_code[0])<<endl;
        for(int j=0;j<n-i+1;j++){
            if(gray_code[pos]&(1<<j)){
                cin>>val;
                cout<<i<<" "<<i+j<<endl;
                cout<<flush;
            }
        }
    }
    return 0;
}