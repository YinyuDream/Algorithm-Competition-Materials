#include<bits/stdc++.h>
#define LD long double
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--) 
using namespace std;
const int N=8e5+10;
ll M=998244353;
const int mo=998244353;
const int G=3;
const int mxl=(1<<18);
struct NTT{
    int n,m,wn[N],a[N],b[N],C[N],D[N],inv[N];
    int fsp(int x,int y) {int ans;for (ans=1;y;y>>=1,x=1ll*x*x%mo) if (y&1) ans=1ll*ans*x%mo; return ans;}
    void pre(){
        inv[0]=inv[1]=1;
        rep(i,2,N-1) inv[i]=(1ll*inv[mo%i]*(mo-(mo/i)))%mo; 
        int x=fsp(G,(mo-1)/mxl); wn[mxl>>1]=1;
        rep(i,(mxl>>1)+1,mxl-1) wn[i]=1ll*wn[i-1]*x%mo;
        dep(i,(mxl>>1)-1,1) wn[i]=wn[i<<1];
    }
    inline int add(int x,int y) {return x+y>=mo?x+y-mo:x+y;} 
    void clear()
    {
        rep(i,0,n) a[i]=b[i]=0;
    }
    void ntt(int *a,int f)
    {
        if (f>0){
            for (int k=n>>1;k;k>>=1)
              for (int i=0;i<n;i+=k<<1)
                for (int j=0;j<k;j++){
                    int x=a[i+j],y=a[i+j+k];
                    a[i+j+k]=1ll*(x-y+mo)*wn[k+j]%mo;
                    a[i+j]=add(x,y);
                } 
        } else{
            for (int k=1;k<n;k<<=1)
              for (int i=0;i<n;i+=(k<<1))
                for (int j=0;j<k;j++){
                    int x=a[i+j],y=1ll*a[i+j+k]*wn[k+j]%mo;
                    a[i+j+k]=add(x,mo-y);
                    a[i+j]=add(x,y);
                }
            for (int i=0,inv=mo-(mo-1)/n;i<n;i++) a[i]=1ll*a[i]*inv%mo;
            reverse(a+1,a+n);
        }
    }
    void getcj(ll *A,ll *B,__int128_t *C,int len)
    {
        for (n=1;n<2*len;n*=2);
        for (int i=0;i<len;i++) a[i]=(A[i]%mo+mo)%mo,b[i]=(B[i]%mo+mo)%mo;
        ntt(a,1); ntt(b,1);
        for (int i=0;i<n;i++) a[i]=1ll*a[i]*b[i]%mo;
        ntt(a,-1);
        for (int i=0;i<2*len;i++) C[i]=a[i];
        clear();
    }
}F;
int n;
ll a[N],t1[N],t2[N],t3[N],t4[N];
__int128_t b[N],tp[N],t5[N],gg[N];
__int128_t X[N],Y[N];
/*
3
1 2 3
*/
#define mid (h+t)/2
void s1(int h,int t)
{
	if (h==t) return;
	s1(h,mid); s1(mid+1,t);
	rep(i,h,mid) t3[i-h]=t1[i];
	rep(i,mid+1,t) t4[i-mid-1]=t2[i];
	F.getcj(t3,t4,t5,mid-h+1);
	rep(i,h,mid) t3[i-h]=0;
	rep(i,mid+1,t) t4[i-mid-1]=0;
	rep(i,0,t-h) b[i+h+mid+1]+=t5[i];
}

void s2(int h,int t)
{
	if (h==t) return;
	s2(h,mid); s2(mid+1,t);
	rep(i,h,mid) t3[mid-i]=a[i];
	rep(i,mid+1,t) t4[i-mid-1]=a[i];
	F.getcj(t3,t4,t5,mid-h+1);
	rep(i,h,mid) t3[mid-i]=0;
	rep(i,mid+1,t) t4[i-mid-1]=0;
	rep(i,0,t-h) gg[i+1]+=t5[i];
}

//2*j-i
void s3(int h,int t)
{
	if (h==t) return;
	s3(h,mid); s3(mid+1,t);
	rep(i,h,mid) t3[mid-i]=a[i];
	rep(i,mid+1,t) t4[(i-mid-1)*2]=a[i];
	F.getcj(t3,t4,t5,max(mid-h+1,(t-mid-1)*2)+1);
	rep(i,h,mid) t3[mid-i]=0;
	rep(i,mid+1,t) t4[(i-mid-1)*2]=0;
	rep(i,0,(t-mid-1)*2+mid-h) Y[i+mid+2]-=2*t5[i];
}
//2*j-i-mid-2



//2*i+n-j+1
void s4(int h,int t)
{
	if (h==t) return;
	s4(h,mid); s4(mid+1,t);
	rep(i,h,mid) t3[(i-h)*2]=a[i];
	rep(i,mid+1,t) t4[t-i]=a[i];
	F.getcj(t3,t4,t5,(mid-h)*2+1);
	rep(i,h,mid) t3[(i-h)*2]=0;
	rep(i,mid+1,t) t4[t-i]=0;
	rep(i,0,(mid-h)*2+t-(mid+1)) Y[i-t+2*h+n+1]-=2*t5[i];
}
//2*i-2*h+t-j
void MAIN(){
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	F.pre(); cin>>n;
	for(int i=0;i<n;++i)
	{
		cin>>a[i];
		a[i]%=M;
	}
	F.getcj(a,a,b,n+2);
	ll whatever=((ll)n*(ll)(n-1)/(ll)2)%M;
	for(int i=0;i<=2*n-2;++i)
	{
		b[i]=b[i]%M*whatever%M;
	}
	for (int i=0;i<n;++i) b[2*i]-=(__int128_t)a[i]*a[i]*(i+1)*(n-i); 
	rep(i,0,n-1) t1[i]=2*a[i]*(1ll*i*i%mo+i-n)%mo,t2[i]=a[i];
	s1(0,n-1);
	rep(i,0,n-1) t1[i]=2*a[i]%mo,t2[i]=a[i]*i%mo*i%mo;
	s1(0,n-1);
	rep(i,0,n-1) t1[i]=2*a[i]*(-i-n)%mo,t2[i]=a[i]*i%mo;
	s1(0,n-1);
	memset(X,0,sizeof(X));
	memset(Y,0,sizeof(Y));
	for (int i=0;i<n;++i) Y[0]+=a[i]*a[i];
	F.getcj(a,a,tp,n+2);
	rep(i,0,2*n-1)
	{ 
	  Y[i+2]-=tp[i];
	  Y[2*n-i]-=tp[i];
    }
    s2(0,n-1);
    rep(i,0,2*n-1)
	{ 
	  (Y[i]+=2*gg[i])%=mo;
	  (Y[2*n-i+2]+=2*gg[i])%=mo;
    }
	for(int i=0;i<=2*n-2;++i)
	{
		if(i>=2) 
		{
			Y[i]=(Y[i]+Y[i-2])%M;
			X[i]=(X[i]+X[i-2])%M;
		}
		X[i]=(X[i]+Y[i])%M;
		b[i]=(b[i]+X[i])%M;
	}
	memset(X,0,sizeof(X));
	memset(Y,0,sizeof(Y));
	rep(i,0,2*n-1) 
	  Y[i+1]-=2*tp[i]; 
	rep(i,0,n-1) Y[2*i+1]+=2*a[i]*a[i];
	__int128 sum=0;
	dep(i,n-1,0)
	{
		Y[2*i+1]+=a[i]*sum*2;
		Y[n+i+1]+=a[i]*sum*2;
		sum+=a[i];
	}
	sum=0;
	rep(i,0,n-1)
	{
		Y[i]+=a[i]*sum*2;
		Y[2*i+1]+=a[i]*sum*2;
		sum+=a[i];
	}
	s3(0,n-1);
	s4(0,n-1);
	for(int i=0;i<=2*n-2;++i)
	{
		if(i>=1) 
		{
			Y[i]=(Y[i]+Y[i-1])%M;
			X[i]=(X[i]+X[i-1])%M;
		}
		X[i]=(X[i]+Y[i])%M;
		b[i]=(b[i]+X[i])%M;
	}
	
	
	for(int i=0;i<=2*n-2;++i)
	{
		ll tmp=b[i];
		tmp=(tmp%M+M)%M;
		cout<<tmp<<"\n";
	}
	return;
}
int main(){
	ios::sync_with_stdio(false);
	MAIN();
	return 0;
}
/*
*/
