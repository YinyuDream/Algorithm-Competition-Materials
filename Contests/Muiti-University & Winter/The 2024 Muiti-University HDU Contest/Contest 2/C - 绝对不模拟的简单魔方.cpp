#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
class Rubik_Cube{
    private:
        int cube[6][3][3];
    public:
        Rubik_Cube(){
            for(int i=0;i<6;i++){//0:上 2：左 3：前 4：右 5：后 1：下
                for(int j=0;j<3;j++){
                    for(int k=0;k<3;k++){
                        cube[i][j][k]=i;
                    }
                }
            }
        }
        void rotate(int x,int y){//x:哪个面（0-5） y:旋转方向（0:顺时针 1:逆时针）
            
        }
}

void solve(){
    
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}