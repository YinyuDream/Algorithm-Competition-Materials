#include<bits/stdc++.h>
using namespace std;
int T,cnt,x_1,y_1,x_2,y_2,x_3,y_3;
bool check(int x_1,int y_1,int x_2,int y_2)
{
	if(x_1==x_2)return true;
	if(y_1==y_2)return true;
	return false;
}
int main(){
	cin>>T;
	while(T--){
		cin>>x_1>>y_1>>x_2>>y_2>>x_3>>y_3;
		cnt=check(x_1,y_1,x_2,y_2)+check(x_1,y_1,x_3,y_3)+check(x_2,y_2,x_3,y_3);
		if(cnt==2){
			cout<<"NO"<<endl;
		}else{
			cout<<"YES"<<endl;
		}
	}
	return 0;
}