#include<bits/stdc++.h>
using namespace std;
int A,B;
int main(){
    cin>>A>>B;
    for(int i=1;i<=6;i++){
        for(int j=1;j<=6;j++){
            for(int k=1;k<=6;k++){
                int red=0,black=0;
                if(i==1||i==4)red+=i;
                if(j==1||j==4)red+=j;
                if(k==1||k==4)red+=k;
                black=i+j+k-red;
                if(red==A&&black==B){
                    cout<<"Yes"<<endl;
                    return 0;
                }
            }
        }
    }
    cout<<"No"<<endl;
    return 0;
}