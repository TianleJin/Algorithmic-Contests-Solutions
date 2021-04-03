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
 
const int dx4[] = { -1, 0, 1, 0 };
const int dy4[] = { 0, -1, 0, 1 };
const int dx8[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
const int dy8[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
 
// https://cses.fi/problemset/task/1137
// eulerian tour + fenwick tree
const int mxn = 200005;
int n, q;
int timer = 0;
vector<int> graph[mxn];
int ar[mxn], st[mxn], en[mxn];
ll ft[mxn];
 
void upd(int idx, int val) {
	for (int i = idx + 1; i <= n; i += i & -i) {
		ft[i] += val;
	}
}
 
ll qry(int s, int e) {
	ll ans = 0;
	for (int i = e + 1; i > 0; i -= i & -i) {
		ans += ft[i];
	}
	for (int i = s; i > 0; i -= i & -i) {
		ans -= ft[i];
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
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> ar[i];
	}
 
	for (int i = 0; i + 1 < n; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
 
	dfs(1);
 
	for (int i = 1; i <= n; i++) {
		upd(st[i], ar[i]);
	}
 
	for (int i = 0; i < q; i++) {
		int t, s;
		cin >> t >> s;
		if (t == 1) {
			int x;
			cin >> x;
			upd(st[s], x - ar[s]);
			ar[s] = x;
		}
		else {
			cout << qry(st[s], en[s]) << endl;
		}
	}
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}