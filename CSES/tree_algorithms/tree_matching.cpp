#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// https://cses.fi/problemset/task/1130/
const int mxn = 200005;
int n;
int ans = 0;
vector<int> graph[mxn];
bool used[mxn];

void dfs(int node, int parent = 0) {
	for (int i : graph[node]) {
		if (i != parent) {
			dfs(i, node);
		}
	}
	for (int i : graph[node]) {
		if (i != parent && !used[i]) {
			used[i] = true;
			used[node] = true;
			ans++;
			return;
		}
	}
}

void solve() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	dfs(1);
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}