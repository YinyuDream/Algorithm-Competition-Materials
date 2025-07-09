#include<bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    int a,b;
    scanf("%d%d",&a,&b);
    int k=5;
    for(int i=1;i<=a;i++){
        k--;
        if(k==-1)k=4;
        for(int j=1+k;j<=a;j+=5){
            printf("%d %d\n",i,j);
            fflush(stdout);
            string s;
            cin>>s;
            if(s=="hit"){
                for(int k=i+1;k<=a&&k<=i+4;k++){
                    printf("%d %d\n",i,k);
                    fflush(stdout);
                    cin>>s;
                }
                for(int k=i-1;k>=1&&k>=i-4;k--){
                    printf("%d %d\n",k,j);
                    fflush(stdout);
                    cin>>s;
                }
                for(int k=i+1;k<=a&&k<=i+4;k++){
                    printf("%d %d\n",k,j);
                    fflush(stdout);
                    cin>>s;
                }
                for(int k=i-1;k>=1&&k>=i-4;k--){
                    printf("%d %d\n",k,j);
                    fflush(stdout);
                    cin>>s;
                }
            }
        }
    }
}

int main()
{
    int t = 1;
    // std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}