#include <bits/stdc++.h>
using namespace std;
#define SIZE (int)(1e6+10)
struct node
{
    int x,y,k;
};
vector<node> vec;
#define ll long long
int n;
void devide(int x,int y,int c,int k)
{
    if(c==1&&k==1) return;
    if(c==k&&c*k<=49) {node a;a.x=x,a.y=y,a.k=c;vec.push_back(a);return;}
    if(c==k&&c*k>49)
    {
        devide(x,y,c/2,k/2);
        devide(x,y+k/2,c/2,k/2+k%2);
        devide(x+c/2,y,c/2+c%2,k/2);
        devide(x+c/2,y+k/2,c/2+c%2,k/2+k%2);
        node a;a.x=x,a.y=y,a.k=c;vec.push_back(a);
        return;
    }
    if(c>=k)
    {
        devide(x,y,k,k);
        devide(x+k,y,c-k,k);
    }
    if(c<k){
        devide(x,y,c,c);
        devide(x,y+c,c,k-c);
    }
//    devide(x,y,c/2,k/2);
//    devide(x,y+k/2,c/2,k/2+k%2);
//    devide(x+c/2,y,c/2+c%2,k/2);
//    devide(x+c/2,y+k/2,c/2+c%2,k/2+k%2);
    if(c==k){node a;a.x=x,a.y=y,a.k=c;vec.push_back(a);}
}
int main ( )
{
    cin>>n;
    devide(1,1,n,n);
    cout<<vec.size()<<endl;
    for(int i=0;i<vec.size();i++)
    printf("%d %d %d\n",vec[i].x,vec[i].y,vec[i].k);
    system("pause");
}