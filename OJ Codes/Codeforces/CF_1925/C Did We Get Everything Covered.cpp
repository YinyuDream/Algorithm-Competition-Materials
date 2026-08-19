#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+10;
int T,n,k,m,cnt_seg,cnt_alp;
int num[26];
char s[maxn],lst[maxn];
int main(){
	cin>>T;
	while(T--){
        memset(num,0,sizeof num);
        cnt_seg=cnt_alp=0;
		cin>>n>>k>>m>>s+1;
        for(int i=1;i<=m;i++){
            if(num[s[i]-'a']==0){
                cnt_alp++;
            }
            num[s[i]-'a']++;
            if(cnt_alp==k){
                cnt_alp=0;
                lst[++cnt_seg]=s[i];
                memset(num,0,sizeof num);
            }
        }
        if(cnt_seg>=n){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
            for(int i=1;i<=cnt_seg;i++){
                cout<<lst[i];
            }
            for(int i=0;i<=k-1;i++){
                if(num[i]==0){
                    for(int j=1;j<=n-cnt_seg;j++){
                        cout<<char(i+'a');
                    }
                    break;
                }
            }
            cout<<endl;
        }
	}
	return 0;
}