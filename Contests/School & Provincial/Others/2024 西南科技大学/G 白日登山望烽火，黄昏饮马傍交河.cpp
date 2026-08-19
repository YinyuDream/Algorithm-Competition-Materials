#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T--){
        int x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;
        long long dis1=(x1-x2)*(x1-x2)+(-y1-y2)*(-y1-y2);
        long long dis2=(-x1-x2)*(-x1-x2)+(y1-y2)*(y1-y2);
        cout<<(dis1<dis2?'x':'y')<<endl;
    }
    return 0;
}