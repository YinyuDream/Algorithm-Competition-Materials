#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        if(x>=60)
            cout<<"AC"<<endl;
        else
            cout<<"WA"<<endl;
    }
    return 0;
}