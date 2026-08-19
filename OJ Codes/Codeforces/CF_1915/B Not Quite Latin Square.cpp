#include<bits/stdc++.h>
using namespace std;
int T,book[150];
char a[3][3];
int main(){
    cin>>T;
    while(T--){
        memset(book,0,sizeof book);
        for(int i=0;i<3;i++)
            cin>>a[i];
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                book[a[i][j]]++;
        if(book['A']<3)cout<<'A';
        else if(book['B']<3)cout<<'B';
        else cout<<'C';
        cout<<endl;
    }
    return 0;
}