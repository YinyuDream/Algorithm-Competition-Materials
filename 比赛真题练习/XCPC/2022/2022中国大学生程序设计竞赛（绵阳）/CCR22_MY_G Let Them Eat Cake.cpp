#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n,top;
int a[maxn][21],book[maxn];
bool check()
{
    bool flag=false;
    memset(book,0,sizeof(book));
    for(int i=1;i<=a[0][top];i++)
        if(a[i][top]<a[i-1][top]||a[i][top]<a[i+1][top])
            book[i]=1,flag=true;
    return flag;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i][0];
    a[0][0]=n;
    while(check()){
        top++;
        for(int i=1;i<=a[0][top-1];i++)
            if(book[i]==0)
                a[++a[0][top]][top]=a[i][top-1];
        
    }
    cout<<top<<endl;
    return 0;
}