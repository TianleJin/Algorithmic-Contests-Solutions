#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <string.h>
#include <assert.h>
using namespace std;

const int mxn = 200;
int c, a[mxn], colour[mxn];
bool vis[mxn];
vector<int> curr;

void dfs(int i) {
    vis[i] = true;
    curr.push_back(i);
    if (!vis[a[i] - 1]) {
        dfs(a[i] - 1);
    }
}

bool solve(int N, int K) {
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    for (int k = 0; k < K; k++) {
        c = 1;
        memset(vis, false, sizeof(vis));
        memset(colour, 0, sizeof(colour));

        for (int i = 0; i < N; i++) {
            if (!vis[i]) {
                curr.clear();
                dfs(i);
                for (int j = 0; j < curr.size(); j++) {
                    if (j > 0 && j % 10 == 0) {
                        c++;
                    }
                    colour[curr[j]] = c;
                }
                c++;
            }
        }

        for (int i = 0; i < N; i++) {
            cout << colour[i] << " \n"[i + 1 == N];
        }
        cout.flush();

        int res;
        cin >> res;
        if (res == 0) {
            for (int i = 0; i < N; i++) {
                cin >> a[i];
            }
        }
        else if (res == 1) {
            return true;
        }
        else {
            return false;
        }
    }
    return false;
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int T, N, K;
    cin >> T >> N >> K;
    for (int tt = 1; tt <= T; tt++) {
        if (!solve(N, K)) {
            return 0;
        }
    }
}