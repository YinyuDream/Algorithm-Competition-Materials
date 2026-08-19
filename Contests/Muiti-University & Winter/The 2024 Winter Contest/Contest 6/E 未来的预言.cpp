#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,l,num_p,num_r;
char t[10],s[maxn];
int work(int l,int r)
{
    int num=0;
    for(int i=l;i<=r;i++){
        num=num*10+t[i]-'0';
    }
    return num;
}
int main(){
    cin>>(t+1)>>(s+1);
    n=work(3,strlen(t+1));
    l=strlen(s+1);
    for(int i=1;i<=l;i++){
        if(s[i]=='R'){
            num_r++;
            if(num_r>n/2){
                cout<<"kou!"<<endl<<i;
                return 0;
            }
        }else{
            num_p++;
            if(num_p>n/2){
                cout<<"yukari!"<<endl<<i;
                return 0;
            }
        }
    }
    cout<<"to be continued."<<endl<<l;
    return 0;
}