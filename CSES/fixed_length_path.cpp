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

// centroid decomposition + frequency map
const int mxn = 200001;
int n, k;
vector<int> graph[mxn];
int subtree[mxn];

ll ans = 0;
int cnt[mxn]{ 1 }, max_depth;
bool processed[mxn];

int get_subtree_size(int node, int parent = 0) {
	subtree[node] = 1;
	for (int i : graph[node]) {
		if (!processed[i] && i != parent) {
			subtree[node] += get_subtree_size(i, node);
		}
	}
	return subtree[node];
}

int get_centroid(int desired, int node, int parent = 0) {
	for (int i : graph[node]) {
		if (!processed[i] && i != parent && subtree[i] >= desired) {
			return get_centroid(desired, i, node);
		}
	}
	return node;
}

void get_cnt(int node, int parent, int filling, int depth = 1) {
	if (depth > k) return;
	max_depth = max(max_depth, depth);
	if (filling) cnt[depth]++;
	else ans += cnt[k - depth];
	for (int i : graph[node]) {
		if (!processed[i] && i != parent) {
			get_cnt(i, node, filling, depth + 1);
		}
	}
}

void centroid_decomp(int node = 1) {
	int centroid = get_centroid(get_subtree_size(node) / 2, node);
	processed[centroid] = true;
	max_depth = 1;
	for (int i : graph[centroid]) {
		if (!processed[i]) {
			get_cnt(i, centroid, false);
			get_cnt(i, centroid, true);
		}
	}
	fill(cnt + 1, cnt + max_depth + 1, 0);
	for (int i : graph[centroid]) {
		if (!processed[i]) {
			centroid_decomp(i);
		}
	}
}

void solve() {
	cin >> n >> k;
	for (int i = 0; i + 1 < n; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	centroid_decomp();
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}