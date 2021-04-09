#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int dx4[] = { -1, 0, 1, 0 };
const int dy4[] = { 0, -1, 0, 1 };
const int dx8[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
const int dy8[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

// https://cses.fi/problemset/task/1133/
// dp on tree
const int mxn = 200005;
int n;
int timer = 0;
vector<int> graph[mxn];
ll dp[mxn], cnt[mxn], tot[mxn];

void dfs1(int node, int parent = 0) {
	cnt[node] = 1;
	for (int i : graph[node]) {
		if (i != parent) {
			dfs1(i, node);
			cnt[node] += cnt[i];
			tot[node] += tot[i] + cnt[i];
		}
	}
}

void dfs2(int node, int parent = 0) {
	if (parent) {
		dp[node] = dp[parent] + cnt[1] - cnt[parent] + tot[parent] - tot[node] + cnt[parent] - cnt[node] - cnt[node];
	}
	for (int i : graph[node]) {
		if (i != parent) {
			dfs2(i, node);
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

	dfs1(1);

	/*
	for (int i = 1; i <= n; i++) {
		cout << "node " << i << " first: " << fst[i] << endl;
		cout << "node " << i << " second: " << snd[i] << endl;
	}
	*/

	dfs2(1);
	
	for (int i = 1; i <= n; i++) {
		cout << dp[i] + tot[i] << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}