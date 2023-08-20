#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <string.h>
#include <assert.h>
using namespace std;

const int long long inf = 4e18;

long long dp(vector<long long>& zero, vector<long long>& one, long long c) {
    int n = zero.size(), m = one.size();
    vector<vector<long long>> f(n + 1, vector<long long>(m + 1, inf));
    f[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        f[i][0] = min(f[i][0], f[i - 1][0] + 2 * zero[i - 1]);
        if (i >= 2) {
            f[i][0] = min(f[i][0], f[i - 2][0] + 2 * zero[i - 1] + c); 
        }
    }   

    for (int j = 1; j <= m; j++) {
        f[0][j] = min(f[0][j], f[0][j - 1] + 2 * one[j - 1]);
        if (j >= 2) {
            f[0][j] = min(f[0][j], f[0][j - 2] + 2 * one[j - 1] + c);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            f[i][j] = min(f[i][j], f[i - 1][j] + 2 * zero[i - 1]);
            f[i][j] = min(f[i][j], f[i][j - 1] + 2 * one[j - 1]);
            f[i][j] = min(f[i][j], f[i - 1][j - 1] + 2 * max(zero[i - 1], one[j - 1]));
            if (i >= 2) {
                f[i][j] = min(f[i][j], f[i - 2][j] + 2 * zero[i - 1] + c); 
            }
            if (j >= 2) {
                f[i][j] = min(f[i][j], f[i][j - 2] + 2 * one[j - 1] + c); 
            }
        }
    }
    return f[n][m];
}

void solve(int tt) {
    int n, c;
    cin >> n >> c;
    vector<long long> pos_zero, pos_one, neg_zero, neg_one;
    for (int i = 0; i < n; i++) {
        int x, s;
        cin >> x >> s;
        if (x < 0) {
            if (s == 0) {
                neg_zero.push_back(-x);
            }
            else {
                neg_one.push_back(-x);
            }
        }
        else {
            if (s == 0) {
                pos_zero.push_back(x);
            }
            else {
                pos_one.push_back(x);
            }
        }
    }

    sort(neg_zero.begin(), neg_zero.end());
    sort(neg_one.begin(), neg_one.end());
    sort(pos_zero.begin(), pos_zero.end());
    sort(pos_one.begin(), pos_one.end());

    long long left = dp(neg_zero, neg_one, c);
    long long right = dp(pos_zero, pos_one, c);
    cout << "Case #" << tt << ": " << left + right << "\n"; 
}

int main() {
    int T;
    cin >> T;
    for (int tt = 1; tt <= T; tt++) {
        solve(tt);
    }
}