#include<cstdio>
using namespace std;
int month[13]={0,31,-1,31,30,31,30,31,31,30,31,30,31};
int yy,mm;
int Cheak_year(int year)
{
	if(year%100!=0)
		if(year%4==0)return 29;
		else return 28;
	else
		if(year%400==0)return 29;
		else return 28;	
}
int main(){
	scanf("%d%d",&yy,&mm);
	printf("%d",month[mm]!=-1?month[mm]:Cheak_year(yy));
	return 0;
}
