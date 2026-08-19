#include<bits/stdc++.h>
using namespace std;
int n, m, ans;
int mapp[12][12],fa[150];
int find(int a)
{
	if (fa[a] == a)return a;
	fa[a] = find(fa[a]);
	return fa[a];
}
int main()
{
	for(int i=1;i<=10;i++){
		for(int j=1;j<=10;j++){
			cin>>mapp[i][j];
			ans+=!mapp[i][j];
		}
	}
	for (int i = 0; i <= 144; i++)
	{
		fa[i] = i;
	}
	for(int i=0;i<=11;i++)
		for(int j=0;j<=10;j++)
			if(!(mapp[i][j]^mapp[i][j+1])){
				int fx=find(i*12+j),fy=find(i*12+j+1);
				fa[fx]=fy;
			}
	for(int i=0;i<=10;i++)
		for(int j=0;j<=11;j++)
			if(!(mapp[i][j]^mapp[i+1][j])){
				int fx=find(i*12+j),fy=find((i+1)*12+j);
				fa[fx]=fy;
			}
	for(int i=1;i<=10;i++)
		for(int j=1;j<=10;j++)
			if(!mapp[i][j]){
				int fx=find(i*12+j),fy=find(0);
				if(fx==fy)ans--;
			}
	cout<<ans<<endl;
	return 0;
}