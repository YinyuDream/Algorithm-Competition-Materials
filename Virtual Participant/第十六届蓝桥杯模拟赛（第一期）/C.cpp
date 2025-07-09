#include<bits/stdc++.h>
using namespace std;
int main(){
    int x=1;
    while(x*x*x<2024){
        x++;
    }
    cout<<x*x*x-2024<<endl;
    return 0;
}