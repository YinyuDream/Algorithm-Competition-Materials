#include<cstdio>
using namespace std;
typedef long long ll;
ll n;
int main(){
    //freopen("triangle.in","r",stdin);
    //freopen("triangle.out","w",stdout);
    scanf("%lld",&n);
    printf("%lld\n",n*(n-1)*(n-2)*(n-3)*(n-4)*(n-5)/720);
}