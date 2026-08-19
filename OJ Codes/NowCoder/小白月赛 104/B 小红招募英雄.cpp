#include<bits/stdc++.h>
using namespace std;
int main(){
    double p1,p2,p3,p4,p5;
    cin>>p1>>p2>>p3>>p4>>p5;
    cout<<fixed<<setprecision(10)<<1-(pow(p1+p2+p3,10)+pow(p1+p2+p3,9)*(p4+p5)*10);
}