#include <iostream>
#include<vector>
#include<set>
#include<print>
using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  for (int ti = 0; ti < t; ti += 1) {
    int n, m;
    cin >> n >> m;
    vector<set<int>> adj(n + 1);
    for (int i = 0, u, v; i < m; i += 1) {
      cin >> u >> v;
      adj[u].insert(v);
      adj[v].insert(u);
    }
    vector<tuple<int, int, int>> ans;
    for (int i = 1; i <= n; i += 1) {
      while (adj[i].size() >= 2) {
        int u = *adj[i].begin();
        adj[i].erase(adj[i].begin());
        int v = *adj[i].begin();
        adj[i].erase(adj[i].begin());
        adj[u].erase(i);
        adj[v].erase(i);
        ans.emplace_back(i, u, v);
        if (adj[u].find(v) != adj[u].end()) {
          adj[u].erase(v);
          adj[v].erase(u);
        } else {
          adj[u].insert(v);
          adj[v].insert(u);
        }
      }
    }
    vector<int> s;
    vector<pair<int, int>> p;
    for (int i = 1; i <= n; i += 1) {
      if (adj[i].size() == 0) {
        s.push_back(i);
      } else if (*adj[i].begin() > i) {
        p.emplace_back(i, *adj[i].begin()); 
      }
    }
    if (!p.empty()) {
      auto [x, y] = p.back();
      p.pop_back();
      for (int u : s) {
        ans.emplace_back(x, y, u);
        tie(x, y) = pair(x, u);
      }
      for (auto [u, v] : p) {
        ans.emplace_back(y, u, v);
      }
    }
    cout << ans.size() << '\n';
    for (auto [x, y, z] : ans) cout << x << " " << y << " " << z << '\n';
  }
}