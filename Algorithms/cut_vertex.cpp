#include <bits/stdc++.h>
using namespace std;

const int mxn = 2e5;
int n, m, t = 0, disc[mxn], low[mxn];
bool ans[mxn], vis[mxn];
vector<int> g[mxn];

void dfs(int u, int p = -1) {
    ++t;
    disc[u] = t;
    low[u] = t;
    vis[u] = true;

    int children = 0;
    for (int v : g[u]) {
        if (!vis[v]) {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            children++;
            if (p != -1 && low[v] >= disc[u]) {
                ans[u] = true;
            }
        }
        else if (v != p) {
            low[u] = min(low[u], disc[v]);
        }
    }

    if (p == -1 && children > 1) {
        ans[u] = true;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(0);

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (ans[i]) {
            cnt += 1;
        }
    }

    cout << cnt << "\n";
    for (int i = 0; i < n; i++) {
        if (ans[i]) {
            cout << i + 1 << "\n";
        }
    }
}
