#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
typedef unsigned long long ll;

const int N = 64;
ll grid[3003][50];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	
	string row;
	for (int i = 0; i < n; i++) {
		cin >> row;
		for (int s = 0, b = 0; s < n; s += N, b++) {
			ll rep = 0;
			for (int j = s; j < min(s + N, n); j++) {
				rep <<= 1;
				if (row[j] == '1') {
					rep++;
				}
			}
			grid[i][b] = rep;
		}
	}

	ll ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int count = 0;
			for (int b = 0; b <= n / N; b++) {
				count += __builtin_popcountll(grid[i][b] & grid[j][b]);
			}
			ans += count * (count - 1) >> 1;
		}
	}
	cout << ans << endl;
}