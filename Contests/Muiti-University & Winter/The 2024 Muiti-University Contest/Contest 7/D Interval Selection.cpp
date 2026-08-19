#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using hash_t = uint64_t;
auto random_address = [] { char *p = new char; delete p; return uint64_t(p); };
const uint64_t SEED = chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1);
mt19937_64 rng(SEED);
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll t=1;
	cin>>t;
	while(t--){
		int N;
		cin >> N;
		int K;
		cin >> K;
	
		vector<hash_t> hash_values(N + 1);
		for (int i = 0; i <= N; i++)
			hash_values[i] = rng();
		set<int>s;
		vector<int> freq(N + 1, 0);
		vector<queue<int>> indices(N + 1);
		vector<hash_t> hashes(N + 1, 0);
		unordered_map<hash_t, int> hash_freq;
		hash_freq[hashes[0]]++;
		int64_t answer = 0;
		int start = 0;
		vector<int>num(N+1,0);
		for(int i=0; i < N;i++){
			cin>>num[i];
			s.insert(num[i]);
		}
		int now=1;
		map<int,int>mp;
		for(auto x:s){
			mp[x]=now++;
		}
		for (int i = 0; i < N; i++) {
			int a=mp[num[i]];
			if (indices[a].size() >= K) {
				int remove = indices[a].front();
				indices[a].pop();
				
				while (start <= remove) {
					hash_freq[hashes[start]]--;
					start++;
				}
			}
			
			int before = freq[a];
			freq[a] = (freq[a] + 1) % K;
			hashes[i + 1] = hashes[i] + (freq[a] - before) * hash_values[a];
			answer += hash_freq[hashes[i + 1]];
			hash_freq[hashes[i + 1]]++;
			indices[a].push(i);
		}
		cout << answer << '\n';
	}
}