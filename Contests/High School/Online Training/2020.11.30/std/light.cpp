#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)

const int maxn = 5e5 + 100;
const int inf = 1e9;

int n;

string poc_stanje;
vector <vector <int> > graf;

int dp[maxn][2][2];

void precalc(int cvor, int rod) {
	int suma = 0;
	bool parnost = poc_stanje[cvor] == '0';
	for(int dijete : graf[cvor]) {
		if(dijete == rod) continue;
		precalc(dijete, cvor);
		if(dp[dijete][0][0] != inf) suma += dp[dijete][0][0] + (dp[dijete][0][0] == 0 ? 0 : 3);
		else {
			suma += dp[dijete][0][1] + 1;
			parnost = !parnost;
		}
	}
	if(suma || poc_stanje[cvor] == '0') suma++;
	dp[cvor][0][parnost] = suma;
	return;
}

int rek(int cvor, int rod, int gore_vr, bool gore_par) {
	int ret = inf, suma;
	bool parnost;
	if(dp[cvor][0][0] != inf) parnost = 0;
	else parnost = 1;
	suma = dp[cvor][0][parnost];
	for(int dijete : graf[cvor]) {
		if(dijete == rod) continue;
		int nova_suma = suma;
		bool nova_parnost = parnost;
		if(dp[dijete][0][0] != inf) nova_suma -= dp[dijete][0][0] + (dp[dijete][0][0] == 0 ? 0 : 3);
		else {
			nova_suma -= dp[dijete][0][1] + 1;
			nova_parnost = !nova_parnost;
		}
		if(nova_suma == 1 && !nova_parnost) nova_suma = 0;
		int nova_gore_vr = nova_suma;
		if(!nova_gore_vr && gore_vr) nova_gore_vr = 1;
		nova_gore_vr += gore_vr;
		if(gore_par) nova_gore_vr += 1;
		else if(gore_vr) nova_gore_vr += 3;
		ret = min(ret, rek(dijete, cvor, nova_gore_vr, gore_par ^ nova_parnost));
		if(nova_parnost == 0) {
			if(nova_suma == 0) nova_suma = 1;
			dp[cvor][1][0] = min(dp[cvor][1][0], nova_suma + dp[dijete][1][1]);
			dp[cvor][1][1] = min(dp[cvor][1][1], nova_suma + dp[dijete][1][0] + 2);
		}
		else {
			dp[cvor][1][0] = min(dp[cvor][1][0], nova_suma + dp[dijete][1][0] + 2);
			dp[cvor][1][1] = min(dp[cvor][1][1], nova_suma + dp[dijete][1][1]);
		}
	}
	dp[cvor][1][parnost] = min(dp[cvor][1][parnost], max(1, dp[cvor][0][parnost]));
	if(gore_vr == 0) ret = min(ret, dp[cvor][1][1]);
	else if(gore_par) ret = min(ret, dp[cvor][1][0] + gore_vr + 1);
	else ret = min(ret, dp[cvor][1][1] + gore_vr + 3);
	bool uk_parnost = 0;
	if(dp[cvor][0][1] != inf) uk_parnost = 1;
	int uk_suma = dp[cvor][0][parnost];
	if(!uk_suma) uk_suma = 1;
	uk_suma += gore_vr;
	if(gore_par) {
		uk_parnost = !uk_parnost;
		uk_suma += 1;
	}
	else if(gore_vr) uk_suma += 3;
	int mini[2] = {inf, inf};
	for(int dijete : graf[cvor]) {
		if(dijete == rod) continue;
		bool dijete_parnost = 0;
		if(dp[dijete][0][1] != inf) dijete_parnost = 1;
		int prije = dp[dijete][0][dijete_parnost];
		if(dijete_parnost) prije += 1;
		else if(prije) prije += 3;
		int nova_suma = uk_suma - prije;
		bool nova_parnost = uk_parnost ^ dijete_parnost;
		ret = min(ret, dp[dijete][1][0] + 2 + nova_suma + mini[nova_parnost]);
		ret = min(ret, dp[dijete][1][1] + nova_suma + mini[!nova_parnost]);
		if(!dijete_parnost) {
			mini[0] = min(mini[0], dp[dijete][1][1] - prije);
			mini[1] = min(mini[1], dp[dijete][1][0] + 2 - prije);
		}
		else {
			mini[0] = min(mini[0], dp[dijete][1][0] + 2 - prije);
			mini[1] = min(mini[1], dp[dijete][1][1] - prije);
		}
	}
	return ret;
}

int main() {

  freopen("light.in","r",stdin);
  freopen("light.out","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cin >> n >> poc_stanje;
	REP(i, n) REP(j, 2) REP(k, 2) dp[i][j][k] = inf;
	graf.insert(graf.begin(), n, vector<int>());
	int a, b;
	REP(i, n - 1) {
		cin >> a >> b;
		a--; b--;
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	precalc(0, -1);
	cout << rek(0, -1, 0, 0) << "\n";
	return 0;
}
