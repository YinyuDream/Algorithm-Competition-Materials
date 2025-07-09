#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	freopen("data.in","w",stdout);
	srand(unsigned(time(0)));
	n=rand()%20;
	cout<<n<<endl;
	for(int i=1;i<=n;i++)
		printf("%d ",rand());
}