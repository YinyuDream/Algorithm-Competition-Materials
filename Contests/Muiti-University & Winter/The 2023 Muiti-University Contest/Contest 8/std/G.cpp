#include<bits/stdc++.h>
using namespace std;
typedef long double db;
const db pi=acos(-1.0L);
const db eps=1e-9;
struct Point
{
    db x,y;
    explicit Point(db _x=0,db _y=0):x(_x),y(_y){}
    Point operator - (const Point& t)const
    {
        return Point(x-t.x,y-t.y);
    }
    Point operator / (const db t)const
    {
        return Point(x/t,y/t);
    }
    db operator * (const Point& t)const
    {
        return x*t.y-y*t.x;
    }
    db len()const
    {
        return sqrt(x*x+y*y);
    }
    Point norm()const
    {
        return *this/len();
    }
};
db cal(db z)
{
    db s=sin(z),c=cos(z);
    return (s/c/c+log(abs((1+s)/c)))/2;
}
db solve(db a,db c)
{
    if(min(a,c)<eps)return 0;
    db t=atan2(c,a);
    return (a*a*a*cal(t)+c*c*c*cal(pi/2-t))/3;
}
db solve(db a,db c,db d)
{
    if(c*d<0)return solve(a,abs(c))+solve(a,abs(d));
    c=abs(c),d=abs(d);
    if(c<d)swap(c,d);
    return solve(a,c)-solve(a,d);
}
db solve(db a,db b,db c,db d)
{
    if(a*b<0)return solve(abs(a),c,d)+solve(abs(b),c,d);
    a=abs(a),b=abs(b);
    if(a<b)swap(a,b);
    return solve(a,c,d)-solve(b,c,d);
}
int solve()
{
    Point s[4];
    for(int i=0;i<4;i++)
        scanf("%Lf%Lf",&s[i].x,&s[i].y);
    db a=(s[0]-s[2])*(s[3]-s[2]).norm(),b=(s[1]-s[2])*(s[3]-s[2]).norm();
    db c=(s[2]-s[0])*(s[1]-s[0]).norm(),d=(s[3]-s[0])*(s[1]-s[0]).norm();
    if(a>b)swap(a,b);
    if(c>d)swap(c,d);
    return 0*printf("%.18Lf\n",solve(a,b,c,d)/((b-a)*(d-c)));
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}
