#include<bits/stdc++.h>
using namespace std;
double r,a,b,h;
int main(){
    cin>>r>>a>>b>>h;
    double theta=atan(2*h/(a-b));
    double h=(r*sin(theta)-b/2)*tan(theta)+r*cos(theta);
    if(h>0)cout<<setprecision(11)<<"Stuck"<<endl<<h;
    else cout<<"Drop";
    return 0;
}