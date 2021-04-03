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

// https://cses.fi/problemset/task/1139
// eulerian tour + distinct element count range queries
const int mxn = 200005;
int n, q;
int timer = 0;
vector<int> graph[mxn];
vector<pii> query[mxn];
unordered_map<int, int> mp;
int cr[mxn], st[mxn], en[mxn], ar[mxn], ft[mxn], ans[mxn];
 
void upd(int idx, int val) {
	for (int i = idx + 1; i <= n; i += i & -i) {
		ft[i] += val;
	}
}
 
int qry(int idx) {
	int ans = 0;
	for (int i = idx + 1; i > 0; i -= i & -i) {
		ans += ft[i];
	}
	return ans;
}
 
void dfs(int node, int parent = 0) {
	st[node] = timer++;
	for (int i : graph[node]) {
		if (i != parent) {
			dfs(i, node);
		}
	}
	en[node] = timer - 1;
}
 
void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> cr[i];
	}
 
	for (int i = 0; i + 1 < n; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
 
	dfs(1);
	
	for (int i = 1; i <= n; i++) {
		ar[st[i]] = cr[i];
	}
	
	for (int i = 1; i <= n; i++) {
		query[en[i]].push_back({ st[i], i });
	}
 
	for (int i = 0; i < n; i++) {
		upd(i, 1);
	}
 
	mp.reserve(mxn);
 
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int x = ar[i];
		if (mp.find(x) == mp.end()) {
			cnt++;
		}
		else {
			upd(mp[x], -1);
		}
		mp[x] = i;
		for (pii j : query[i]) {
			ans[j.second] = cnt - qry(j.first - 1);
		}
	}
 
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << ' ';
	}
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}