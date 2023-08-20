#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <string.h>
#include <assert.h>
using namespace std;

const int mxn = 1024;
const long long inf = 4e18;
int n;
pair<long long, long long> target, children[mxn], sweets[mxn];
bool dp[mxn][mxn];

long long dist(pair<long long, long long> p1, pair<long long, long long> p2) {
    return (p2.first - p1.first) * (p2.first - p1.first) + (p2.second - p1.second) * (p2.second - p1.second);
}

void solve(int tt) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> children[i].first >> children[i].second;
    }
    cin >> target.first >> target.second;
    for (int i = 0; i < n; i++) {
        cin >> sweets[i].first >> sweets[i].second;
    }

    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < (1 << n); j++) {
            dp[i][j] = false;
        }
    }

    dp[0][0] = true;
    for (int i = 1; i < (1 << n); i++) {
        for (int j = 1; j < (1 << n); j++) {
            if (__builtin_popcount(i) == __builtin_popcount(j)) {
                for (int k = 0; k < n; k++) {
                    if (i >> k & 1) {
                        long long best_dist = inf;
                        for (int l = 0; l < n; l++) {
                            if (j >> l & 1) {
                                best_dist = min(best_dist, dist(children[k], sweets[l]));
                            }
                        }
                        if (best_dist > dist(children[k], target)) {
                            break;
                        }
                        for (int l = 0; l < n; l++) {
                            if (j >> l & 1) {
                                if (dist(children[k], sweets[l]) == best_dist && dp[i ^ 1 << k][j ^ 1 << l]) {
                                    dp[i][j] = true;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    if (!dp[(1 << n) - 1][(1 << n) - 1]) {
        cout << "Case #" << tt << ": IMPOSSIBLE\n";
        return;
    }
   
    cout << "Case #" << tt << ": POSSIBLE\n"; 

    vector<pair<int, int>> ans;
    int i = (1 << n) - 1, j = (1 << n) - 1;
    while (i != 0) {
        bool found = false;
        for (int k = 0; k < n && !found; k++) {
            if (i >> k & 1) {
                long long best_dist = inf;
                for (int l = 0; l < n; l++) {
                    if (j >> l & 1) {
                        best_dist = min(best_dist, dist(children[k], sweets[l]));
                    }
                }
                for (int l = 0; l < n && !found; l++) {
                    if (j >> l & 1) {
                        if (dist(children[k], sweets[l]) == best_dist && dp[i ^ 1 << k][j ^ 1 << l]) {
                            ans.push_back({k + 1, l + 2});
                            i ^= 1 << k;
                            j ^= 1 << l;
                            found = true;
                        }
                    }
                }
            }
        }
    }

    for (int k = 0; k < n; k++) {
        cout << ans[k].first << " " << ans[k].second << "\n";
    }
}

int main() {
    int T;
    cin >> T;
    for (int tt = 1; tt <= T; tt++) {
        solve(tt);
    }
}