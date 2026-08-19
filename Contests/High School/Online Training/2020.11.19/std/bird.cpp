#pragma GCC target("avx")
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")

#include <cstdio>
#include <cstring>

using namespace std;

const long long mod=1e9+7;

int n,k,a,b;

struct M
{
  int s[270][270],r,c;
  void clear()
  {
    memset(s,0,sizeof(s));
  }
}Ye,inw,LUZqwq,ans;

M operator * (M a,M b)
{
  M now;
  now.r=a.r;
  now.c=b.c;
  now.clear();
  for(int i=1;i<=a.r;i++)
  {
    for(int j=1;j<=b.c;j++)
    {
      unsigned long long nowans=0;
      int cnt=0;
      for(int k=1;k<=a.c;k++)
      {
        cnt++;
        nowans+=(unsigned long long)a.s[i][k]*b.s[k][j];
        if(cnt==14) nowans%=mod,cnt=0;
      }
      now.s[i][j]=nowans%mod;
    }
  }
  return now;
}

M ksm(M a,int x)
{
  M ans=a;
  x--;
  while(x)
  {
    if(x&1) ans=ans*a;
    a=a*a;
    x>>=1;
  }
  return ans;
}

int iksm(int a,int x)
{
  int ans=a;
  x--;
  while(x)
  {
    if(x&1) ans=(long long)ans*a%mod;
    a=(long long)a*a%mod;
    x>>=1;
  }
  return ans;
}

int main()
{
  freopen("bird.in","r",stdin);
  freopen("bird.out","w",stdout);
  scanf("%d%d%d%d",&n,&k,&a,&b);
  n-=2;
  Ye.r=2*k;
  Ye.c=2*k;
  LUZqwq.r=2*k;
  LUZqwq.c=2*k;
  for(int i=1;i<=k;i++)
  {
    if(i!=k) Ye.s[i][i+1]=1;
    if(i!=1) Ye.s[i][i-1]=1;
    Ye.s[i][i]=1;
    if(i!=k) Ye.s[k+i][k+i+1]=1;
    if(i!=1) Ye.s[k+i][k+i-1]=1;
    Ye.s[k+i][k+i]=1;
  }
  for(int i=a+1;i<=b-1;i++)
  {
    if(i!=1) Ye.s[i-1][k+i]=1;
    if(i!=k) Ye.s[i+1][k+i]=1;
    Ye.s[i][k+i]=1;
  }
  for(int i=1;i<=k;i++)
  {
    if(i!=k) LUZqwq.s[i][i+1]=1;
    if(i!=1) LUZqwq.s[i][i-1]=1;
    LUZqwq.s[i][i]=1;
    if(i!=k) LUZqwq.s[k+i][k+i+1]=1;
    if(i!=1) LUZqwq.s[k+i][k+i-1]=1;
    LUZqwq.s[k+i][k+i]=1;
  }
  inw.r=1;
  inw.c=2*k;
  inw.clear();
  inw.s[1][k/2]=1;
  ans=inw*ksm(Ye,n);
  ans=ans*LUZqwq;
  printf("%d",(int)((long long)ans.s[1][k+k/2]*iksm(n,mod-2)%mod));
}
