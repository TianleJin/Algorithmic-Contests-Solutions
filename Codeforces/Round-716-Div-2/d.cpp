#include <iostream>
#include <array>
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


const int mxn = 3e5;
int n, q, a[mxn], t[mxn << 2];
vector<int> ind[mxn + 1];

int cnt(int num, int l, int r) {
	return upper_bound(ind[num].begin(), ind[num].end(), r) - lower_bound(ind[num].begin(), ind[num].end(), l);
}

void build(int idx = 1, int l = 0, int r = n) {
	if (r - l < 2) {
		t[idx] = a[l];
		return;
	}
	int mid = (l + r) / 2;
	build(2 * idx, l, mid);
	build(2 * idx + 1, mid, r);
	t[idx] = cnt(t[2 * idx], l, r - 1) > cnt(t[2 * idx + 1], l, r - 1) ? t[2 * idx] : t[2 * idx + 1];
}

int query(int x, int y, int idx = 1, int l = 0, int r = n) {
	if (x >= r || y <= l) return 0;
	if (x <= l && r <= y) {
		return cnt(t[idx], x, y - 1);
	}
	int mid = (l + r) / 2;
	return max(query(x, y, 2 * idx, l, mid), query(x, y, 2 * idx + 1, mid, r));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		ind[a[i]].push_back(i);
	}

	build();

	for (int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r; --l; r;
		cout << max(1, 2 * query(l, r) - r + l) << endl;
	}
}