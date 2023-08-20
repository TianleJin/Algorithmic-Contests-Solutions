#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;

struct BipartiteMatching {
    int n, m;
    vector<int> match, dist;
    vector<vector<int>> edges;
    BipartiteMatching(int n, int m) : n(n), m(m) {
        match.resize(n + m + 1, 0);
        dist.resize(n + 1);
        edges.resize(n + m + 1);
    }

    void add_edge(int u, int v) {
        edges[u + 1].push_back(v + n + 1);
        edges[v + n + 1].push_back(u + 1);
    }

    bool bfs() {
        queue<int> q;

        dist[0] = inf;
        for (int u = 1; u <= n; u++) {
            if (match[u]) {
                dist[u] = inf;
            }
            else {
                dist[u] = 0;
                q.push(u);
            }
        }
        
        while (!q.empty()) {
            int u = q.front(); q.pop();
            if (u != 0) {
                for (int v : edges[u]) {
                    if (dist[match[v]] == inf) {
                        dist[match[v]] = dist[u] + 1;
                        q.push(match[v]);
                    }
                }
            }
        }
        return dist[0] != inf;
    }

    bool dfs(int u) {
        if (u != 0) {
            for (int v : edges[u]) {
                if (dist[match[v]] == dist[u] + 1) {
                    if (dfs(match[v])) {
                        match[u] = v;
                        match[v] = u;
                        return true;
                    }
                }
            }
            dist[u] = inf;
            return false;
        }
        return true;
    }

    int solve() {
        int ans = 0;
        while (bfs()) {
            for (int u = 1; u <= n; u++) {
                if (match[u] == 0 && dfs(u)) {
                    ans += 1;
                }
            }
        }
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;

    BipartiteMatching bpm(n, m);
    for (int i = 0; i < k; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        bpm.add_edge(u, v);
    }

    int ans = bpm.solve();
    
    cout << ans << "\n";
    for (int u = 1; u <= n; u++) {
        if (bpm.match[u]) {
            cout << u << " " << bpm.match[u] - n << "\n";
        }
    }
}
