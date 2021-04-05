#include <iostream>
#include <string>
#include <array>
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
const int dxknight[] = { -1, -1, -2, -2, 1, 1, 2, 2 };
const int dyknight[] = { 2, -2, 1, -1, 2, -2, 1, -1 };

// https://cses.fi/problemset/task/1689/
// Warnsdorff's algorithm
const int sze = 8;
const int mod = 1e9 + 7;
int x, y;
int board[sze][sze], deg[sze][sze];
int count(int x, int y) {
	int ans = 0;
	for (int j = 0; j < sze; j++) {
		int nx = x + dxknight[j];
		int ny = y + dyknight[j];
		if (nx < 0 || nx >= sze || ny < 0 || ny >= sze) continue;
		ans++;
	}
	return ans;
}

void reduce(int x, int y) {
	for (int j = 0; j < sze; j++) {
		int nx = x + dxknight[j];
		int ny = y + dyknight[j];
		if (nx < 0 || nx >= sze || ny < 0 || ny >= sze) continue;
		--deg[nx][ny];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> y >> x; --x; --y;

	for (int i = 0; i < sze; i++) {
		for (int j = 0; j < sze; j++) {
			deg[i][j] = count(i, j);
		}
	}

	for (int i = 1; i <= sze * sze; i++) {
		board[x][y] = i; reduce(x, y);

		int bx = -1;
		int by = -1;
		int lo = sze + 1;

		for (int j = 0; j < sze; j++) {
			int nx = x + dxknight[j];
			int ny = y + dyknight[j];
			if (nx < 0 || nx >= sze || ny < 0 || ny >= sze || board[nx][ny]) continue;
			if (deg[nx][ny] < lo) {
				lo = deg[nx][ny];
				bx = nx;
				by = ny;
			}
		}

		if (i + 1 < sze * sze) {
			assert(bx != -1 && by != -1);
		}
		x = bx;
		y = by;
	}

	for (int i = 0; i < sze; i++) {
		for (int j = 0; j < sze; j++) {
			cout << board[i][j] << (j + 1 < sze ? ' ' : '\n');
		}
	}
}