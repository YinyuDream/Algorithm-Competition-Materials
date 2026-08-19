#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n,pos_1,pos_2,pos_0,pos_su;
int p[maxn];
vector<int>v;
int main(){
	cin>>T;
	while(T--){
        v.clear();
		cin>>n;
        if(n==2){
            cout<<"! "<<0<<' '<<1<<endl;
            fflush(stdout);
            continue;
        }
        pos_1=0,pos_2=1;
        char ch;
        for(int i=2;i<n-1;i++){
            cout<<'?'<<' '<<pos_1<<' '<<i<<' '<<pos_2<<' '<<i<<endl;
            fflush(stdout);
            cin>>ch;
            if(ch=='>'){
                pos_2=i;
            }else if(ch=='<'){
                pos_1=i;
            }else{
                pos_1=i;
            }
        }
        cout<<'?'<<' '<<pos_1<<' '<<n-1<<' '<<pos_2<<' '<<n-1<<endl;
        fflush(stdout);
        cin>>ch;
        if(ch=='>'){
            pos_0=pos_1;
        }else if(ch=='<'){
            pos_0=pos_2;
        }else{
            pos_0=pos_1;
        }
        if(pos_0==0){
            cout<<'?'<<' '<<1<<' '<<pos_0<<' '<<1<<' '<<n-1<<endl;
            fflush(stdout);
            cin>>ch;
        }else{
            cout<<'?'<<' '<<0<<' '<<pos_0<<' '<<0<<' '<<n-1<<endl;
            fflush(stdout);
            cin>>ch;
        }
        if(ch=='>'){
            pos_0=pos_0;
        }else if(ch=='<'){
            pos_0=n-1;
        }else{
            pos_0=pos_0;
        }
        pos_1=0,pos_2=1;
        for(int i=2;i<=n;i++){
            cout<<'?'<<' '<<pos_1<<' '<<pos_0<<' '<<pos_2<<' '<<pos_0<<endl;
            fflush(stdout);
            cin>>ch;
            if(ch=='>'){
                v.clear();
                v.push_back(pos_1);
                pos_2=i;
            }else if(ch=='<'){
                v.clear();
                v.push_back(pos_2);
                pos_1=i;
            }else{
                if(pos_1>pos_2)swap(pos_1,pos_2);
                v.push_back(pos_2);
                pos_2=i;
            }
        }
        pos_1=0,pos_2=1;
        for(int i=0;i<v.size()-1;i++){
            cout<<'?'<<' '<<v[pos_1]<<' '<<v[i]<<' '<<v[pos_2]<<' '<<v[i]<<endl;
            fflush(stdout);
            cin>>ch;
            if(ch=='>'){
                pos_1=i;
            }else if(ch=='<'){
                pos_2=i;
            }else{
                pos_1=i;
            }
        }
        cout<<'?'<<' '<<v[pos_1]<<' '<<v[v.size()-1]<<' '<<v[pos_2]<<' '<<v[v.size()-1]<<endl;
        fflush(stdout);
        cin>>ch;
        if(ch=='>'){
            pos_su=pos_2;
        }else if(ch=='<'){
            pos_su=pos_1;
        }else{
            pos_su=pos_1;
        }
        if(pos_su==0){
            cout<<'?'<<' '<<v[1]<<' '<<v[pos_su]<<' '<<v[1]<<' '<<v[v.size()-1]<<endl;
            fflush(stdout);
            cin>>ch;
        }else{
            cout<<'?'<<' '<<v[0]<<' '<<v[pos_su]<<' '<<v[0]<<' '<<v[v.size()-1]<<endl;
            fflush(stdout);
            cin>>ch;
        }
        if(ch=='>'){
            pos_su=v.size()-1;
        }else if(ch=='<'){
            pos_su=pos_su;
        }
        cout<<"! "<<pos_0<<' '<<v[pos_su]<<endl;
        fflush(stdout);
	}
	return 0;
}