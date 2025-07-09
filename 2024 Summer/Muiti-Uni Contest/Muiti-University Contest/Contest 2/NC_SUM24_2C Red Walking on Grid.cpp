#include<bits/stdc++.h>
using ll = long long;
using namespace std;
ll maxs=0;
char num[1000002][2];
ll dp[1000002][2];
void solve()
{
	ll n;
	cin>>n;
	for(int i=0;i<2;i++)
	for(int j=0;j<n;j++){
		cin>>num[j][i];
	}
	ll now=0;
	ll maxs=0;
	ll t=0;
	ll pre=-1;
	for(int i=0;i<n;i++){
		if(num[i][0]=='W'&&num[i][1]=='W'){
            now+=2*t;
            t=0;
			maxs=max(maxs,now);
			pre=-1;
			now=0;
            continue;
		}
		else{
			if(num[i][0]=='W'&&num[i][1]=='R'){
				now+=t*2;
				if(pre==-1){
					now++;
				}
				else{
					if(t==0&&pre==1){
						maxs=max(maxs,now);
						now=1;
					}
                    else{
                        if(t%2==0&&pre==0){
                            now++;
                        }
                        else{
                            if(t%2==1&&pre==1){
                                now++;
                            }
                        }
                    }
				}
                t=0;
				pre=0;
			}
			else{
				if(num[i][0]=='R'&&num[i][1]=='W'){
				now+=t*2;
				if(pre==-1){
					now++;
				}
				else{
					if(t==0&&pre==0){
						maxs=max(maxs,now);
						now=1;
					}
                    else{
                        if(t%2==0&&pre==1){
                            now++;
                        }
                        else{
                            if(t%2==1&&pre==0){
                                now++;
                            }
                        }
                    }
				}
					pre=1;
                    t=0;
				}
				else{
					t++;
				}
			}
		}
	}	
	now+=t*2;
	maxs=max(maxs,now);
	if(maxs!=0)
	cout<<maxs-1<<'\n';
	else{
		cout<<0<<'\n';
	}
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int t = 1;
//	cin>>t;
	while (t--) {
		solve();
	}
	return 0;
}