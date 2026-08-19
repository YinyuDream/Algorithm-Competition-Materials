#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;
template <typename T>
inline void _read(T& x){
    char ch=getchar();bool sign=true;
    while(!isdigit(ch)){if(ch=='-')sign=false;ch=getchar();}
    for(x=0;isdigit(ch);ch=getchar())x=x*10+ch-'0';
    if(!sign)x=-x;
}
int T;
struct node{
    int p,a;
    bool mark;
    node(){}
    node(int P,int A){
        p=P;a=A;mark=false;
    }
};
node car[50005];
bool cmp(node A,node B){
    if(A.a==B.a)return A.p>B.p;
    else return A.a<B.a;
}
int q[50005];
double meet[50005];
int rear;
double solve(int i,int j){
    //if(car[i].p==car[j].p)return 0.0;
    //if((car[i].a<car[j].a&&car[j].p>car[i].p)||(car[i].a>car[j].a&&car[j].p<car[i].p))return -1.0;
    double a1=car[i].a,a2=car[j].a,p1=car[i].p,p2=car[j].p;
    return sqrt(2.0*(p2-p1)/(a1-a2));
}
int main(){
	//freopen("car.in","r",stdin);
	//freopen("car.out","w",stdout);
    T=1;
    int i,j,k,n;
    while(T--){
        memset(car,0,sizeof(car));
        _read(n);
        int ans=0;
        for(i=1;i<=n;i++){
            _read(car[i].p);
            _read(car[i].a);
        }
        sort(car+1,car+1+n,cmp);
        int id=1;
        for(i=2;i<=n;i++){
            if(car[i-1].a==car[i].a&&car[i-1].p==car[i].p){
			//处理p，a都相同的车，mark为true表示存在另一个与他参数相同的车 
                car[i-1].mark=true;
                car[i].mark=true;
            }
        }
        int tot=1;
        for(i=2;i<=n;i++){
            if(car[i].a!=car[i-1].a)car[++tot]=car[i]; 
			//相同加速度的车我们只留一个p最大的 
        }
        //tot=保留的车的数量 
        rear=1;
        q[rear]=1; //把第一个车加进栈 
        for(i=2;i<=tot;i++){ //依次讨论每一辆车 
            while(rear>0&&car[i].p>=car[q[rear]].p)rear--; 
			//如果栈顶车p比当前车小，那么栈顶车可以扔掉(因为它p、a都比当前车小) 
            while(rear>=2){ //栈里还有大于两个车 
            	//meet[i]存储q[i]和q[i+1]两辆车相交的时间点 
                if(solve(i,q[rear])<meet[rear-1]+1e-5)rear--; 
				//如果栈顶两车的相交点 不小于 当前车和栈顶车的相交点 栈顶可以扔掉 
                else break;
            }
            q[++rear]=i; //当前车入栈 
            if(rear>1)meet[rear-1]=solve(q[rear-1],q[rear]); //存储对应meet值 
        }
        //q里面就是所有的领跑者 
        for(i=1;i<=rear;i++)if(car[q[i]].mark==false)ans++;
        printf("%d\n",ans);
    }
}
