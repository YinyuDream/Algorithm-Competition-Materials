#include<bits/stdc++.h>
using namespace std;
int T,n,cnt,pos;
int main(){
    cin>>T;
    while(T--){
        cnt=pos=0;
        cin>>n;
        for(int i=2,q;i<=n;i+=2){
            cout<<'?'<<' '<<i-1<<' '<<i<<endl;
            fflush(stdout);
            cin>>q;
            if(q==1){
                cnt++;
                pos=i;
            }
        }
        if(cnt>=2){
            cout<<"! 1"<<endl;
            fflush(stdout);
        }else if(cnt==0){
            if(n%2==0){
                cout<<"! 1"<<endl;
                fflush(stdout);
            }else{
                cnt=0;
                for(int i=1,q;i<=3;i++){
                    cout<<'?'<<' '<<i<<' '<<n<<endl;
                    fflush(stdout);
                    cin>>q;
                    if(q==1){
                        cnt++;
                    }
                }
                if(cnt==3){
                    cout<<"! 2"<<endl;
                    fflush(stdout);
                }else{
                    cout<<"! 1"<<endl;
                    fflush(stdout);
                }
            }
        }else{
            int r,q;
            if(pos==2)r=4;
            else r=pos-2;
            cout<<'?'<<' '<<r<<' '<<pos<<endl;
            fflush(stdout);
            cin>>q;
            if(q==1){
                cout<<'?'<<' '<<r-1<<' '<<pos<<endl;
                fflush(stdout);
                cin>>q;
                if(q==1){
                    cout<<"! 2"<<endl;
                    fflush(stdout);
                }else{
                    cout<<"! 1"<<endl;
                    fflush(stdout);
                }
            }else{
                cout<<'?'<<' '<<r<<' '<<pos-1<<endl;
                fflush(stdout);
                cin>>q;
                if(q==1){
                    cout<<'?'<<' '<<r-1<<' '<<pos-1<<endl;
                    fflush(stdout);
                    cin>>q;
                    if(q==1){
                        cout<<"! 2"<<endl;
                        fflush(stdout);
                    }else{
                        cout<<"! 1"<<endl;
                        fflush(stdout);
                    }
                }else{
                    cout<<"! 1"<<endl;
                    fflush(stdout);
                }
            }
        }
    }
    return 0;
}