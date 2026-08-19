#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int p=1e9+7;
string n,m;
ll a,b,c,d;
struct martix{
	ll a[5][5];
	martix(){
		memset(a,0,sizeof a);
	}
}A,B,C,D;
martix operator*(const martix &a,const martix &b)
{
	martix c;
	for(int i=1;i<=2;i++)
		for(int j=1;j<=2;j++)
			for(int k=1;k<=2;k++)
				c.a[i][j]+=a.a[i][k]*b.a[k][j],
				c.a[i][j]%=p;
	return c;
}
martix qpow(martix a,ll b)
{
	if(b==0){
		martix c;
		c.a[1][1]=c.a[2][2]=1;
		return c;
	}
	martix c=qpow(a,b/2);
	if(b&1)return c*c*a;
	else return c*c;
}
martix qpow(martix a,string b)
{
	martix c;
	int p=b.size()-1;
	c.a[1][1]=c.a[2][2]=1;
	while(p!=-1){
		if((b[p]-'0')%10!=0)
		c=c*qpow(a,b[p]-'0');
		a=qpow(a,10);
		p--;
	}
	return c;
}
string operator-(const string &a,ll b)
{
	string c;
	c=a;
	int l=c.size()-1;
	while(c[l]=='0')l--;
	c[l]--;
	for(int i=l+1;i<c.size();i++)
	c[i]='9';
	return c;
}
int main(){
	cin>>n>>m>>a>>b>>c>>d;
	A.a[1][1]=a,A.a[2][1]=b,A.a[2][2]=1;
	B.a[1][1]=c,B.a[2][1]=d,B.a[2][2]=1;
	C.a[1][1]=C.a[1][2]=1;
	D=C*qpow(qpow(A,m-1)*B,n-1)*qpow(A,m-1);
	cout<<D.a[1][1];
	return 0;
}
