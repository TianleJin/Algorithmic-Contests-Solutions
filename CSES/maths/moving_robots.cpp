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
#include <iomanip>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int dx4[] = { -1, 0, 1, 0 };
const int dy4[] = { 0, -1, 0, 1 };
const int dx8[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
const int dy8[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

const int n = 8;
const int mxn = 101;
double dp[mxn][n][n][n][n];

bool valid(int row, int col) {
	if (row < 0 || row >= n || col < 0 || col >= n) {
		return false;
	}
	return true;
}

int get(int row, int col) {
	int moves = 4;
	if (row == 0 || row + 1 == n) {
		moves--;
	}
	if (col == 0 || col + 1 == n) {
		moves--;
	}
	return moves;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int steps;
	cin >> steps;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dp[0][i][j][i][j] = 1;
		}
	}
	for (int s = 0; s < steps; s++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					for (int l = 0; l < n; l++) {
						for (int m = 0; m < 4; m++) {
							int r = k + dx4[m];
							int c = l + dy4[m];
							if (valid(r, c)) {
								dp[s + 1][i][j][k][l] += dp[s][i][j][r][c] / get(r, c);
							}
						}
					}
				}
			}
		}
	}
	
	double ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			double prob = 1.0;
			for (int k = 0; k < n; k++) {
				for (int l = 0; l < n; l++) {
					prob *= 1.0 - dp[steps][k][l][i][j];
				}
			}
			ans += prob;
		}
	}
	cout << setprecision(6) << fixed << ans << endl;
}

