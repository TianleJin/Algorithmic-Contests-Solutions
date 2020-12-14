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
#include <sstream>
typedef long long ll;
#define vi vector<int>
using namespace std;

int dX[4] = { 0, 0, -1, 1 };
int dY[4] = { -1, 1, 0, 0 };

int N, K;
const int MOD = 998244353;
const int mxn = 200000;
const int mxk = 10;
int L[mxk], R[mxk];
ll dp[mxn];
int main() {
	cin >> N >> K;
	for (int k = 0; k < K; k++) {
		cin >> L[k] >> R[k];
		R[k]++;
	}
	for (int i = 0; i < N; i++) {
		dp[i] = 0;
	}
	dp[0] = 1; dp[1] = MOD - 1;
	for (int i = 0; i < N; i++) {
		if (i > 0) {
			dp[i] = (dp[i] + dp[i - 1] + MOD) % MOD;
		}
		for (int k = 0; k < K; k++) {
			int l = L[k];
			int r = R[k];
			if (i + l < N) {
				dp[i + l] = (dp[i + l] + dp[i] + MOD) % MOD;
			}
			if (i + r < N) {
				dp[i + r] = (dp[i + r] - dp[i] + MOD) % MOD;
			}
		}
	}
	cout << dp[N - 1] << '\n';
}
