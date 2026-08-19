#include<bits/stdc++.h>
using namespace std;
const int maxn=3e3+10;
int n;
int cnt_a[maxn],cnt_b[maxn];
int read()
{
    int num=0;
    char ch=getchar();
    while(ch<'0'||ch>'9')
        ch=getchar();
    while(ch>='0'&&ch<='9'){
        num=num*10+ch-'0';
        ch=getchar();
    }
    return num;
}
int main(){
    n=read();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(read()==1){
                cnt_a[i]++;
                cnt_b[j]++;
            }
        }
    }
    int ans_1=n,ans_2=n;
    for(int i=1;i<=n;i++)
        if(cnt_a[i]==0)
            ans_1--;
    for(int i=1;i<=n;i++)
        if(cnt_b[i]==0)
            ans_2--;
    cout<<min(ans_1,ans_2)<<endl;
    return 0;
}