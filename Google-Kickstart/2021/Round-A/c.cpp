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
typedef vector<int> vi;
typedef pair<int, int> pii;

const int dx[] = { -1, 0, 1, 0 };
const int dy[] = { 0, -1, 0, 1 };

// priority queue
struct Cell {
	int r;
	int c;
	int h;
	Cell(int _r, int _c, int _h) : r(_r), c(_c), h(_h) {}
	bool operator<(Cell const& cell) const {
		return h < cell.h;
	}
};

struct CompareHeight {
	bool operator()(Cell const& c1, Cell const& c2)
	{
		return c1.h < c2.h;
	}
};

ll solve() {
	int R, C;
	cin >> R >> C;
	priority_queue<Cell> pq;
	vector<vector<int>> grid(R, vector<int>(C));
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> grid[i][j];
			if (grid[i][j]) {
				pq.push(Cell(i, j, grid[i][j]));
			}
		}
	}

	ll ans = 0;
	while (!pq.empty()) {
		Cell cell = pq.top();
		pq.pop();
		if (cell.h < grid[cell.r][cell.c]) continue;
		for (int i = 0; i < 4; i++) {
			int nr = cell.r + dx[i];
			int nc = cell.c + dy[i];
			if (0 <= nr && nr < R && 0 <= nc && nc < C && grid[nr][nc] + 1 < cell.h) {
				ans += cell.h - 1LL - grid[nr][nc];
				grid[nr][nc] = cell.h - 1;
				pq.push(Cell(nr, nc, grid[nr][nc]));
			}
		}
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(25);

	int T;
	cin >> T;
	for (int tt = 1; tt <= T; tt++) {
		cout << "Case #" << tt << ": " << solve() << endl;
	}
}