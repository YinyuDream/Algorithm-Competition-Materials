#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n,m,flag;
int q(int x,int y)
{
    int ans;
    cout<<"? "<<x<<" "<<y<<endl;
    fflush(stdout);
    cin>>ans;
    return ans;
}

int main(){
	cin>>T;
	while(T--){
		cin>>n>>m;
        int d1=q(1,1);
        int d2=q(n,1);
        int d4=q(1,m);
        if(d1==0){
            cout<<"! 1 1"<<endl;
            fflush(stdout);
            continue;
        }
        if(d2==0){
            cout<<"! "<<n<<" "<<1<<endl;
            fflush(stdout);
            continue;
        }
        if(d4==0){
            cout<<"! "<<1<<" "<<m<<endl;
            fflush(stdout);
            continue;
        }
        int x_1=(d1-d2+n+1)/2,y_1=(d1+d2+3-n)/2;
        int x_2=(d1+d4+3-m)/2,y_2=(d1-d4+m+1)/2;
        if(x_1<=n&&y_1<=m&&x_1>=1&&y_1>=1&&q(x_1,y_1)==0){
            cout<<"! "<<x_1<<" "<<y_1<<endl;
            fflush(stdout);
        }else{
            cout<<"! "<<x_2<<" "<<y_2<<endl;
            fflush(stdout);
        }
	}
	return 0;
}