#include<bits/stdc++.h>
using namespace std;
int T,n,k,ans;
int f[31];
double max(double a,double b)
{
    return a>b?a:b;
}
double min(double a,double b)
{
    return a<b?a:b;
}
bool equal(double a,int b)
{
    return abs(a-b)<1e-6;
}
int main(){
    cin>>T;
    f[1]=f[2]=1;
    for(int i=3;i<=30;i++)
        f[i]=f[i-1]+f[i-2];
	while(T--){
        cin>>n>>k;
        double mx=n,mn=0;
        ans=0;
        if(k>=30){
            cout<<0<<endl;
            continue;
        }else{
            for(int i=2;i<=k;i++){
                if(i%2==0){
                    mx=min(mx,1.0*f[i-1]*n/f[i]);
                }else{
                    mn=max(mn,1.0*f[i-1]*n/f[i]);
                }
            }
        }
        if(k%2==1){
            mx=min(mx,1.0*f[k-2]*n/f[k-1]);
        }else{
            mn=max(mn,1.0*f[k-2]*n/f[k-1]);
        }
        if(mn>mx)cout<<0<<endl;
        else{
            int imn=mn,imx=mx;
            if(imn==imx)ans=0;
            else ans=imx-imn;
            if(equal(mn,imn))ans++;
            cout<<ans<<endl;
        }
    }
	return 0;
}