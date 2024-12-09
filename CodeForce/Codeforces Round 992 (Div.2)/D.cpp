#include <bits/stdc++.h>
 
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
 
void solve() {
    int n;
    std::cin >> n;
    
    std::vector<std::vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    std::vector<int> a(n);
    int cur = 1;
    auto dfs = [&](this auto &&self, int x, int p = -1) -> void {
        a[x] = cur;
        bool first = true;
        for (auto y : adj[x]) {
            if (y == p) {
                continue;
            }
            if (first) {
                first = false;
                cur++;
                self(y, x);
                cur++;
            } else {
                cur += 2;
                self(y, x);
            }
        }
    };
    dfs(0);
    
    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " \n"[i == n - 1];
    }
}
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}