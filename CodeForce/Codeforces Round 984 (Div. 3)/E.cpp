/*https://codeforces.com/contest/2036/problem/E*/
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k, q;
  cin >> n >> k >> q;
  vector<vector<int>> a(k, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) {
      cin >> a[j][i];
      if (i > 0) {
        a[j][i] |= a[j][i - 1];
      }
    }
  }
  while (q--) {
    int m;
    cin >> m;
    int low = 0, high = n;
    while (m--) {
      int i;
      char c;
      int x;
      cin >> i >> c >> x;
      --i;
      if (c == '<') {
        high = min(high, int(lower_bound(a[i].begin(), a[i].end(), x) - a[i].begin()));
      } else {
        low = max(low, int(upper_bound(a[i].begin(), a[i].end(), x) - a[i].begin()));
      }
    }
    cout << (low >= high ? -1 : low + 1) << '\n';
  }
  return 0;