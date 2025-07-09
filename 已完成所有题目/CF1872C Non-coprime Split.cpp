#include<bits/stdc++.h>
using namespace std;
int T,a,b;
int check(int x)
{
    int lim=sqrt(x)+1;
    for(int i=2;i<=lim;i++){
        if(x%i==0)return i;
    }
    return 0;
}
int main(){
	cin>>T;
	while(T--){
		cin>>a>>b;
        if(b%2==0){
            if(b!=2)cout<<b/2<<" "<<b/2;
            else cout<<-1;
        }
        else if(b%2!=0){
            if(b==1)cout<<-1;
            else{
                if(a!=b){
                    if(b==3)cout<<-1;
                    else cout<<(b-1)/2<<" "<<(b-1)/2;
                }else{
                    int t=check(a);
                    if(t==0)cout<<-1;
                    else{
                        cout<<a/t<<" "<<a-a/t;
                    }
                }
            }
        }
        cout<<endl;
	}
	return 0;
}