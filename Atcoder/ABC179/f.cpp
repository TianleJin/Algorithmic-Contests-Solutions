#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <array>
#include <map>
#include <set>
#include <string>
#include <deque>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <assert.h>
typedef long long ll;
using namespace std;

const int MOD = 998244353;
const int mxn = 200000;
int dX1[4] = { 0, 0, -1, 1 };
int dY1[4] = { -1, 1, 0, 0 };
int dX2[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dY2[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

class SegTree {
public:
	int N;
	vector<int> arr;
	int tree[mxn << 2];
	int lazy[mxn << 2];
	SegTree() : tree{0}, lazy{0} {}

	void init(int N, vector<int>& arr) {
		this->N = N;
		this->arr = arr;
		build(1, 0, N);
		for (int i = 0; i < N << 2; i++) {
			lazy[i] = N;
		}
	}

	void build(int idx, int l, int r) {
		if (r - l < 2) {
			tree[idx] = arr[l]; return;
		}
		int mid = (l + r) / 2;
		build(2 * idx, l, mid);
		build(2 * idx + 1, mid, r);
		tree[idx] = min(tree[2 * idx], tree[2 * idx + 1]);
	}

	void change(int idx, int val) {
		tree[idx] = min(tree[idx], val);
		lazy[idx] = min(lazy[idx], val);
	}

	void push(int idx) {
		if (lazy[idx] != N) {
			change(2 * idx, lazy[idx]);
			change(2 * idx + 1, lazy[idx]);
			lazy[idx] = N;
		}
	}

	void update(int x, int y, int val, int idx, int l, int r) {
		if (x >= r || l >= y) return;
		if (x <= l && r <= y) {
			change(idx, val); return;
		}
		push(idx);
		int mid = (l + r) / 2;
		update(x, y, val, 2 * idx, l, mid);
		update(x, y, val, 2 * idx + 1, mid, r);
		tree[idx] = min(tree[2 * idx], tree[2 * idx + 1]);
	}

	int query(int x, int y, int idx, int l, int r) {
		if (x >= r || l >= y) return N;
		if (x <= l && r <= y) return tree[idx];
		push(idx);
		int mid = (l + r) / 2;
		return min(query(x, y, 2 * idx, l, mid), query(x, y, 2 * idx + 1, mid, r));
	}
};


SegTree seg1, seg2;
int main() {
	int N, Q, t, x;
	cin >> N >> Q;
	vector<int> v1(N, N), v2(N, N);
	seg1.init(N, v1);
	seg2.init(N, v2);
	
	ll ans = (N - 2LL) * (N - 2LL);
	for (int q = 0; q < Q; q++) {
		cin >> t >> x;
		if (t == 1) {
			int l = seg1.query(x, x + 1, 1, 0, N);
			ans += 2LL - l;
			seg2.update(0, l, x, 1, 0, N);
		}
		else {
			int l = seg2.query(x, x + 1, 1, 0, N);
			ans += 2LL - l;
			seg1.update(0, l, x, 1, 0, N);
		}
	}
	cout << ans << '\n';
}
