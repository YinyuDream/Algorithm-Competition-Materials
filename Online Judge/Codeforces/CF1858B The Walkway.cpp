#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int T,n,m,d,cnt,ans,book,num;
int s[maxn];
int main(){
	cin>>T;
	while(T--){
        book=0;
		cin>>n>>m>>d;
        for(int i=1;i<=m;i++)
            cin>>s[i];
        if(s[1]!=1){
            for(int i=m;i>=1;i--){
                s[i+1]=s[i];
            }
            s[1]=1;
            m++;
            book=1;
        }
        cnt=1;
        for(int i=2;i<=m;i++){
            cnt+=(s[i]-s[i-1]-1)/d+1;
        }
        cnt+=(n-s[m])/d;
        ans=cnt;
        num=0;
        for(int i=2;i<=m-1;i++){
            int delta=((s[i+1]-s[i-1]-1)/d)-((s[i+1]-s[i]-1)/d+(s[i]-s[i-1]-1)/d+1);
            if(ans>cnt+delta){
                ans=cnt+delta;
                num=1;
            }else if(ans==cnt+delta){
                num++;
            }
        }
        int delta=((n-s[m-1])/d)-((n-s[m])/d+(s[m]-s[m-1]-1)/d+1);
        if(ans>cnt+delta){
            ans=cnt+delta;
            num=1;
        }else if(ans==cnt+delta){
            num++;
        }
        if(book==0&&ans==cnt){
            num++;
        }
        cout<<ans<<" "<<num<<endl;
	}
	return 0;
}