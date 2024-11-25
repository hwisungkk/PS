#include<iostream>
using namespace std;

using ll = long long;

void solve() {
  int x; ll m; cin >> x >> m;

  // divisible by x
  ll p = m - m % x;
  ll ans = p / x - (x < p);
  if ((x ^ p) >= 1 && (x ^ p) <= m) ++ans;
  p += x;
  if ((x ^ p) >= 1 && (x ^ p) <= m) ++ans;

  // divisibly by y
  for (int y = 1; y <= min(1LL * x, m); y++) {
    ll cur = x ^ y;
    if (cur % y == 0) {
      ++ans;
    }
  }

  // divisible by both
  if (x <= m) {
    --ans;
  }

  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}