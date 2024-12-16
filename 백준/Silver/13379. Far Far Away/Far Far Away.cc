#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

vector<vector<pair<int, int>>> g;
int d[100001];
int v[100001];

int n, m;

void dfs(int x) {
    for (auto& e : g[x]) {
        int nx = e.first;
        int w = e.second;
        
        if (v[nx] == 0) {
            d[nx] = d[x] + w;
            v[nx] = 1;
            dfs(nx);
        }
    }
}

void reset() {
    memset(d, 0, sizeof(d));
    memset(v, 0, sizeof(v));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, a, b, c;
    cin >> t;

    while (t--) {
        cin >> n >> m;
        
        g.clear();
        g.resize(n + 1);

        for (int i = 0; i < n - 1; i++) {
            cin >> a >> b >> c;
            g[a].push_back({b, c});
        }

        int ma = -1;
        for (int i = 1; i <= n; i++) {
            if (v[i] == 0) {
                d[i] = 0;
                dfs(i);
            }
        }

        for (int i = 1; i <= n; i++) {
            if (d[i] >= m) {
                ma = max(ma, d[i]);
            }
        }

        cout << ma << '\n';

        reset();
    }

    return 0;
}
