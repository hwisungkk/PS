/*https://codeforces.com/contest/2036/problem/A*/
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    bool ok = true;
    for (int i = 0; i < n - 1; i++) {
      int x = abs(a[i] - a[i + 1]);
      ok &= (x == 5 || x == 7);
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
  return 0;
}