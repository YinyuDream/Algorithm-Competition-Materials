#include<cstdio>
#include<ctime>
#include<cstdlib>
using namespace std;
int main(){
	srand((unsigned)time(0));
	printf("%s",rand()%2?"YES":"NO");
}
