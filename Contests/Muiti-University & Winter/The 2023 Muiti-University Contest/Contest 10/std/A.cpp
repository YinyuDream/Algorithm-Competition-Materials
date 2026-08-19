#include<bits/stdc++.h>
using namespace std;
const int sk[8][2] = {{1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}};
const int sn[8][2] = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
const int sb[4][2] = {{1, 1}, {-1, 1}, {-1, -1}, {1, -1}};
int ans[8][8][8][8][8][8][8][8][2], deg[8][8][8][8][8][8][8][8];
bool to[8][8][8][8][8][8][8][8][8];
inline int In(int x, int y) {
	return x >= 0 && x < 8 && y >= 0 && y < 8;
}
inline int Check(int a, int b, int c, int d, int e, int f, int g, int h) {
	if(abs(a - e) == 1 && abs(b - f) == 2)
		return 1;
	if(abs(a - e) == 2 && abs(b - f) == 1)
		return 1;
	if(a != g && b != h && abs(a - g) == abs(b - h)) {
		if(abs(c - g) == abs(d - h) && abs(c - g) < abs(a - g) && (c - g) * (a - g) > 0 && (b - h) * (d - h) > 0)
			return 0;
		if(abs(e - g) == abs(f - h) && abs(e - g) < abs(a - g) && (e - g) * (a - g) > 0 && (b - h) * (f - h) > 0)
			return 0;
		return 1;
	}
	return 0;
}
struct Node {
	int a, b, c, d, e, f, g, h, t;
	Node(int a = 0, int b = 0, int c = 0, int d = 0, int e = 0, int f = 0, int g = 0, int h = 0, int t = 0) : a(a), b(b), c(c), d(d), e(e), f(f), g(g), h(h), t(t) {}
};
queue<Node>q;
int T;
char pbk[5], pwk[5], pn[5], pb[5];
int main() {
	int cnt = 0;
	memset(ans, -1, sizeof ans);
	for(int a = 0; a < 8; ++ a)
		for(int b = 0; b < 8; ++ b) // black king
			for(int c = 0; c < 8; ++ c)
				for(int d = 0; d < 8; ++ d) { // white king
					if(max(abs(a - c), abs(b - d)) <= 1)
						continue;
					for(int e = 0; e < 8; ++ e)
						for(int f = 0; f < 8; ++ f) { // white knight
							if(a == e && b == f)
								continue;
							if(c == e && d == f)
								continue;
							for(int g = 0; g < 8; ++ g)
								for(int h = 0; h < 8; ++ h) { // white bishop
									if(a == g && b == h)
										continue;
									if(c == g && d == h)
										continue;
									if(e == g && f == h)
										continue;
									for(int k = 0; k < 8; ++ k) {
										int na = a + sk[k][0], nb = b + sk[k][1];
										if(!In(na, nb))
											continue;
										if(max(abs(na - c), abs(nb - d)) <= 1)
											continue;
										if(!Check(na, nb, c, d, e, f, g, h)) {
											++ deg[a][b][c][d][e][f][g][h];
											to[na][nb][c][d][e][f][g][h][(k + 4) % 8] = 1;
										}
									}
									if(!deg[a][b][c][d][e][f][g][h] && Check(a, b, c, d, e, f, g, h)) {
// cerr << "One Checkmate Situation: " << endl;
// cerr << "Black King(" << char(a + 'a') << char(b + '1') << ")" << endl;
// cerr << "white King(" << char(c + 'a') << char(d + '1') << ")" << endl;
// cerr << "white Knight(" << char(e + 'a') << char(f + '1') << ")" << endl;
// cerr << "white Bishop(" << char(g + 'a') << char(h + '1') << ")" << endl;
										q.push(Node(a, b, c, d, e, f, g, h, 1)), ans[a][b][c][d][e][f][g][h][1] = 0;
									}
								}
						}
				}
	while(!q.empty()) {
		Node now = q.front();
		q.pop();
// cerr << now.a << " " << now.b << " " << now.c << " " << now.d << " " << now.e << " " << now.f << " " << now.g << " " << now.h << " " << now.t << " " << ans[now.a][now.b][now.c][now.d][now.e][now.f][now.g][now.h][now.t] << endl;
		if(now.t) {
			for(int k = 0; k < 8; ++ k) { // move white king
				int nc = now.c + sk[k][0], nd = now.d + sk[k][1];
				if(!In(nc, nd))
					continue;
				if(max(abs(now.a - nc), abs(now.b - nd)) <= 1)
					continue;
				if(nc == now.e && nd == now.f)
					continue;
				if(nc == now.g && nd == now.h)
					continue;
				if(ans[now.a][now.b][nc][nd][now.e][now.f][now.g][now.h][0] == -1)
					ans[now.a][now.b][nc][nd][now.e][now.f][now.g][now.h][0] = ans[now.a][now.b][now.c][now.d][now.e][now.f][now.g][now.h][1] + 1, q.push(Node(now.a, now.b, nc, nd, now.e, now.f, now.g, now.h, 0));
			}
			for(int k = 0; k < 8; ++ k) { // move white knight
				int ne = now.e + sn[k][0], nf = now.f + sn[k][1];
				if(!In(ne, nf))
					continue;
				if(ne == now.a && nf == now.b)
					continue;
				if(ne == now.c && nf == now.d)
					continue;
				if(ne == now.g && nf == now.h)
					continue;
				if(ans[now.a][now.b][now.c][now.d][ne][nf][now.g][now.h][0] == -1)
					ans[now.a][now.b][now.c][now.d][ne][nf][now.g][now.h][0] = ans[now.a][now.b][now.c][now.d][now.e][now.f][now.g][now.h][1] + 1, q.push(Node(now.a, now.b, now.c, now.d, ne, nf, now.g, now.h, 0));
			}
			for(int k = 0; k < 4; ++ k) {
				for(int d = 1; ; ++ d) { // move white bishop
					int ng = now.g + sb[k][0] * d, nh = now.h + sb[k][1] * d;
					if(!In(ng, nh))
						break;
					if(ng == now.a && nh == now.b)
						break;
					if(ng == now.c && nh == now.d)
						break;
					if(ng == now.e && nh == now.f)
						break;
					if(ans[now.a][now.b][now.c][now.d][now.e][now.f][ng][nh][0] == -1)
						ans[now.a][now.b][now.c][now.d][now.e][now.f][ng][nh][0] = ans[now.a][now.b][now.c][now.d][now.e][now.f][now.g][now.h][1] + 1, q.push(Node(now.a, now.b, now.c, now.d, now.e, now.f, ng, nh, 0));
				}
			}
		}
		else {
			for (int k = 0; k < 8; k++) if (to[now.a][now.b][now.c][now.d][now.e][now.f][now.g][now.h][k]) {
				int na = now.a + sk[k][0], nb = now.b + sk[k][1];
// cerr << "Pre(" << now.a << ", " << now.b << ") Now(" << na << ", " << nb << ") " << now.c << " " << now.d << " " << now.e << " " << now.f << " " << now.g << " " << now.h << endl;
				if(! --deg[na][nb][now.c][now.d][now.e][now.f][now.g][now.h]) {
// cerr << "!" << endl;
// assert(ans[na][nb][now.c][now.d][now.e][now.f][now.g][now.h][1] == -1);
					ans[na][nb][now.c][now.d][now.e][now.f][now.g][now.h][1] = ans[now.a][now.b][now.c][now.d][now.e][now.f][now.g][now.h][0], q.push(Node(na, nb, now.c, now.d, now.e, now.f, now.g, now.h, 1));
				}
			}
		}
	}
cerr << "End." << endl;
	for(scanf("%d", &T); T --; ) {
		scanf("%s%s%s%s", pbk, pwk, pn, pb);
		int a = pbk[0] - 'a', b = pbk[1] - '1', c = pwk[0] - 'a', d = pwk[1] - '1', e = pn[0] - 'a', f = pn[1] - '1', g = pb[0] - 'a', h = pb[1] - '1';
		if(ans[a][b][c][d][e][f][g][h][0] == -1)
			puts("draw");
		else
			printf("win\n%d\n", ans[a][b][c][d][e][f][g][h][0]);
	}
}
