#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <string.h>
#include <assert.h>
using namespace std;


void solve(int tt) {
    int N, C;
    cin >> N >> C;
    vector<int> a(C), b(C), p(N);
    for (int i = 0; i < C; i++) {
        cin >> a[i] >> b[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> p[i];
        p[i]--;
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        int good = C;
        vector<int> cnt(C);
        for (int j = i; j < i + N - 1; j++) {
            int idx = j % N;
            bool was_good = cnt[p[idx]] == 0 || (a[p[idx]] <= cnt[p[idx]] && b[p[idx]] >= cnt[p[idx]]);
            cnt[p[idx]]++;
            bool now_good = cnt[p[idx]] == 0 || (a[p[idx]] <= cnt[p[idx]] && b[p[idx]] >= cnt[p[idx]]);
            if (was_good && !now_good) {
                good--;
            }
            if (!was_good && now_good) {
                good++;
            }
            if (i != j && good == C) {
                ans++;
            } 
        }
    }
    cout << "Case #" << tt << ": " << ans << "\n";
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int T;
    cin >> T;
    for (int tt = 1; tt <= T; tt++) {
        solve(tt);
    }
}