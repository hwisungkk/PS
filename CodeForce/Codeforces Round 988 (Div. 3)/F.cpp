int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> h(n);
    for (int i = 0; i < n; i++) {
      cin >> h[i];
    }
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
      cin >> x[i];
    }
    const int inf = int(1e9) + 10;
    int low = 0, high = inf;
    while (low + 1 < high) {
      int mid = (low + high) >> 1;
      vector<pair<int, int>> e;
      for (int i = 0; i < n; i++) {
        int power = (h[i] + mid - 1) / mid;
        if (power <= m) {
          int from = x[i] - (m - power);
          int to = x[i] + (m - power);
          e.emplace_back(from, +1);
          e.emplace_back(to + 1, -1);
        }
      }
      sort(e.begin(), e.end());
      bool good = false;
      int bal = 0;
      for (auto& [_, v] : e) {
        bal += v;
        if (bal >= k) {
          good = true;
          break;
        }
      }
      if (good) {
        high = mid;
      } else {
        low = mid;
      }
    }
    cout << (high == inf ? -1 : high) << '\n';
  }
  return 0;
}