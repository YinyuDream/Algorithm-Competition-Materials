#include<bits/stdc++.h>
using namespace std;
double dis(double a,double b,double c,double d)
{
    return sqrt((c-a)*(c-a)+(d-b)*(d-b));
}
int main(){
    int T;
    cin>>T;
    while(T--){
        double a,b,c,d;
        cin>>a>>b>>c>>d;
        double d1=dis(-a,b,c,d);
        double d2=dis(a,-b,c,d);
        printf("%.10f\n",min(d1,d2));
    }
    return 0;
}