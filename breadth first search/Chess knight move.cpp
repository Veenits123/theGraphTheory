#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <set>
#include <cstring>
using namespace std;

/* → → → → → → → → → → → → → → → → → → → → → → → → → → → →
	→ → → → → → → → → → → → → → → → → → → → → → → → → → → → */

#define int long long
#define ld long double
#define F first
#define S second
#define P pair <int,int>
#define vi vector <int>
#define vs vector <string>
#define vb vector <bool>
#define all(x) x.begin(),x.end()
#define FOR(a,b) for(int i=a;i<b;i++)
#define REP(a,b) for(int i=a;i<=b;i++)
#define sp(x,y) fixed<<setprecision(y)<<x
#define pb push_back
#define mod 1e9+7
#define endl '\n'

/* → → → → → → → → → → → → → → → → → → → → → → → → → → → →
	→ → → → → → → → → → → → → → → → → → → → → → → → → → → → */

const int N = 1e1 + 5;
int vis[N][N];
int dis[N][N];

int row[] = {0, 2, 2, -2, -2, -1, 1, 1, -1};
int col[] = {0, -1, 1, 1, -1, 2, 2, -2, -2};

bool is_valid(int i, int j) {
	return (i >= 1 && i <= 8 && j >= 1 && j <= 8);
}

int bfs(int sx, int sy, int ex, int ey) {
	queue <P> q;
	q.push({sx, sy});
	vis[sx][sy] = 1;
	dis[sx][sy] = 0;
	while (!q.empty()) {
		P temp = q.front();
		q.pop();
		if (temp.F == ex && temp.S == ey) {
			return dis[ex][ey];
		}
		for (int i = 1; i <= 8; i++) {
			int r = row[i] + temp.F;
			int c = col[i] + temp.S;
			if (!vis[r][c] && is_valid(r, c)) {
				q.push({r, c});
				vis[r][c] = 1;
				dis[r][c] = dis[temp.F][temp.S] + 1;
			}
		}
	}
	return -1;
}

void solve() {

	memset(vis, 0, sizeof(vis));
	memset(dis, 0, sizeof(dis));

	string s, e; cin >> s >> e;

	int sx = s[0] - 'a' + 1, sy = s[1] - '0';
	int ex = e[0] - 'a' + 1, ey = e[1] - '0';

	int ans = 0;
	ans = bfs(sx, sy, ex, ey);
	cout << ans << endl;

	return ;
}

int32_t main() {

	/* → → → → → → → → → → → → → → → → → → → → → → → → → → → →
	→ → → → → → → → → → → → → → → → → → → → → → → → → → → → */

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	/* → → → → → → → → → → → → → → → → → → → → → → → → → → → →
	→ → → → → → → → → → → → → → → → → → → → → → → → → → → → */

	int t; cin >> t; while (t--)
		solve();

	return 0;
}