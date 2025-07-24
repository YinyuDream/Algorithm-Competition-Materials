#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n;
int p[maxn];
vector<int>v;
int main(){
	cin>>T;
	while(T--){
        v.clear();
		cin>>n;
        int pos=0;
        for(int i=1;i<n;i++){
            cout<<"?"<<" "<<pos<<" "<<pos<<" "<<i<<" "<<i<<endl;
            fflush(stdout);
            char ch;
            ch=getchar();
            while(ch!='<'&&ch!='='&&ch!='>')
                ch=getchar();
            if(ch=='<')
                pos=i;
        }
        v.push_back(0);
        int mx=0;
        for(int i=1;i<n;i++){
            mx=v.back();
            cout<<"?"<<" "<<mx<<" "<<pos<<" "<<i<<" "<<pos<<endl;
            fflush(stdout);
            char ch;
            ch=getchar();
            while(ch!='<'&&ch!='='&&ch!='>')
                ch=getchar();
            if(ch=='<'){
                v.clear();
                v.push_back(i);
                mx=i;
            }else if(ch=='='){
                v.push_back(i);
            }
        }
        mx=v.front();
        for(auto i=v.begin()+1;i!=v.end();i++){
            cout<<"?"<<" "<<mx<<" "<<mx<<" "<<*i<<" "<<*i<<endl;
            fflush(stdout);
            char ch;
            ch=getchar();
            while(ch!='<'&&ch!='='&&ch!='>')
                ch=getchar();
            if(ch=='>'){
                mx=*i;
            }
        }
        cout<<"!"<<" "<<pos<<" "<<mx<<endl;
        fflush(stdout);
	}
	return 0;
}