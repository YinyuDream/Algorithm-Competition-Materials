#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+10;
bool book[maxn][maxn];
int delta[12][2]={{2,2},{2,-2},{-2,2},{-2,-2},{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{-2,1},{2,-1},{-2,-1}};
struct node{
    pair<int,int>pos;
	int step;
    node(pair<int,int> _pos,int _step){
        pos=_pos;
        step=_step;
    }
};
pair<int,int> start_point[2],end_point=make_pair(1,1);
int work(pair<int,int> beginning_point)
{
    queue<node> q;
    memset(book,0,sizeof book);
    q.push(node(beginning_point,0));
    book[beginning_point.first][beginning_point.second]=1;
    if(beginning_point==end_point){
        return 0;
	}
    while(q.size())
	{
        node tail=q.front();
        q.pop();
		for(int i=0;i<=11;i++)
		{
			int nx=tail.pos.first+delta[i][0],ny=tail.pos.second+delta[i][1];
			if(nx<1||ny<1||nx>100||ny>100||book[nx][ny])continue;
			if(make_pair(nx,ny)==end_point){
                return tail.step+1;
			}
			book[nx][ny]=1;
            q.push(node(make_pair(nx,ny),tail.step+1));
		}
	}
    return -1;
}
int main()
{
    cin>>start_point[0].first>>start_point[0].second>>start_point[1].first>>start_point[1].second;
    cout<<work(start_point[0])<<endl<<work(start_point[1]);
	return 0;
}
