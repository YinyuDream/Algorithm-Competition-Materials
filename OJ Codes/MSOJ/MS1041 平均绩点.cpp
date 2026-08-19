#include<cstdio>
using namespace std;
int n,cnt,T;
char a;
double ans;
int main()
{
	scanf("%d",&n);scanf("%c",&a);
	for(int i=1;i<=n;i++)
	{
		ans=0;
		cnt=0;
		T=0;
		while(1)
		{
			scanf("%c",&a); 	
			cnt++;
			if(a=='A')ans+=4;
			else if(a=='B')ans+=3;
			else if(a=='C')ans+=2;
			else if(a=='D')ans+=1;
			else if(a=='F')ans+=0;
			else if(a==32||a==9)	
			{
				cnt--;continue;
			}
			else if(a==10&&ans!=0)
			{
				cnt--;break;
			}
			else
			{
				T=-1;ans++;	
			} 			  	
		}
		if(cnt>0&&T!=-1)printf("%.2f\n",ans/cnt);
		if(T==-1)printf("Unknown\n");
	}
	return 0;
}
