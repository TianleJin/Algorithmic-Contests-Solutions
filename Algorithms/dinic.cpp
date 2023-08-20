#include <bits/stdc++.h>
using namespace std;
#define ll long long

const long long inf = 1e18;

struct Dinic {
    int n, source, sink;
    vector<int> dist, idx;
    vector<vector<ll>> flow, cap, edges;
    Dinic(int n, int source, int sink) : n(n), source(source), sink(sink) {
        dist.resize(n, -1);
        idx.resize(n, 0);
        flow.resize(n);
        cap.resize(n);
        edges.resize(n);
        for (int i = 0; i < n; i++) {
            flow[i].resize(n, 0);
            cap[i].resize(n, 0);
        }
    }

    void add_edge(int u, int v, long long c) {
        edges[u].push_back(v);
        edges[v].push_back(u);
        cap[u][v] += c;
    }

    bool bfs() {
        for (int u = 0; u < n; u++) {
            dist[u] = -1;
        }

        queue<int> q;
        dist[source] = 0;
        q.push(source);

        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : edges[u]) {
                if (dist[v] == -1 && cap[u][v] > flow[u][v]) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        return dist[sink] != -1;
    }

    ll dfs(int u, ll f) {
        if (f == 0) {
            return 0;
        }
        if (u == sink) {
            return f;
        }
        for (int& i = idx[u]; i < (int)edges[u].size(); i++) {
            int v = edges[u][idx[u]];
            if (dist[v] == dist[u] + 1 && cap[u][v] > flow[u][v]) {
                ll nf = dfs(v, min(f, cap[u][v] - flow[u][v]));
                if (nf > 0) {
                    flow[u][v] += nf;
                    flow[v][u] -= nf;
                    return nf;
                }
            }
        }
        return 0;
    }

    ll solve() {
        ll mf = 0;
        while (bfs()) {
            for (int i = 0; i < n; i++) {
                idx[i] = 0;
            }
            while (long long f = dfs(source, inf)) {
                mf += f;
            }
        }
        return mf;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    int source = 0, sink = n - 1;
    Dinic max_flow(n, source, sink);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        max_flow.add_edge(a, b, c);
    }
    cout << max_flow.solve();
}
