#include<bits/stdc++.h>
using namespace std;
#define ll long long
int T;
ll n;
char num[3005][3005];
int book[3005][3005];
int main(){
    cin>>T;
    while(T--){
        int a,b;
        cin>>a>>b;
        for(int i=1;i<=a;i++){
            for(int j=1;j<=b;j++){
                cin>>num[i][j];
                book[i][j]=0;
            }
        }
        if(num[1][b]!='.'){
            cout<<"No\n";
            continue;
        }
        for(int i=1;i<=a;i++){
            for(int j=1;j<=b;j++){
                if(num[i][j]=='U'){
                    book[i-1][j]++;
                }
                if(num[i][j]=='D'){
                    book[i+1][j]++;
                }
                if(num[i][j]=='R'){
                    book[i][j+1]++;
                }
                if(num[i][j]=='L'){
                    book[i][j-1]++;
                }
            }
        }
        int f=1;
        int all=0;
        for(int i=1;i<=a;i++){
            for(int j=1;j<=b;j++){
                if(num[i][j]=='C'){
                    if(book[i][j]%2!=0){
                        f=0;
                        break;
                    }
                    all=1;
                    all+=book[i][j];
                }
            }
        }
        if(f==1&&all==a*b-1){
            cout<<"Yes\n";
        } else {
            cout<<"No\n";
        }
    }
    return 0;
}