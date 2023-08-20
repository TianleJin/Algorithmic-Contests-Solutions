#include <bits/stdc++.h>
using namespace std;

const int mxn = 2e5;
int n, m, t = 0, disc[mxn], low[mxn];
bool vis[mxn];
vector<int> g[mxn];
vector<pair<int, int>> ans;

void dfs(int u, int p = -1) {
    ++t;
    disc[u] = t;
    low[u] = t;
    vis[u] = true;

    for (int v : g[u]) {
        if (!vis[v]) {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
        }
        else if (v != p) {
            low[u] = min(low[u], disc[v]);
        }
    }
    if (p != -1 && low[u] == disc[u]) {
        ans.push_back({u, p});
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

    cout << ans.size() << "\n";
    for (pair<int, int> e : ans) {
        cout << e.first + 1 << " " << e.second + 1 << "\n";
    }
}
