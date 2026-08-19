#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int T,n;
int a[maxn],book[26];
int main(){
	cin>>T;
	while(T--){
        memset(book,0,sizeof book);
		cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<=n;i++){
            for(int j=0;j<=25;j++){
                if(book[j]==a[i]){
                    book[j]++;
                    cout<<char(j+'a');
                    break;
                }
            }
        }
        cout<<endl;
	}
	return 0;
}