#include <bits/stdc++.h>
using namespace std;

const int mxn = 500;
const int long long inf = 1e18;
int n, m, source, sink, from[mxn];
long long cap[mxn][mxn];
bool vis[mxn];
vector<int> edge[mxn];

bool bfs() {
    memset(vis, false, sizeof(vis));
    memset(from, -1, sizeof(from));
    queue<int> q;
    q.push(source);
    vis[source] = true;
    while (!q.empty()) {
        int x = q.front(); q.pop();
        for (int y: edge[x]) {
            if (!vis[y] && cap[x][y] > 0) {
                q.push(y);
                vis[y] = true;
                from[y] = x;
            }
        }
    }
    return vis[sink];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(cap, 0, sizeof(cap));
    cin >> n >> m;
    source = 0, sink = n - 1;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
        cap[a][b] += c;
    }

    long long mf = 0;
    while (bfs()) {
        int x = sink;
        long long f = inf;
        while (from[x] != -1) {
            f = min(f, cap[from[x]][x]);
            x = from[x];
        }

        x = sink;
        while (from[x] != -1) {
            cap[from[x]][x] -= f;
            cap[x][from[x]] += f;
            x = from[x];
        }
        mf += f;
    }
    cout << mf << "\n";
}
