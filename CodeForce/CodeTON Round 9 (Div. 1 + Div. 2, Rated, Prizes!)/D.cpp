#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;

const int N = 1e5 + 9;
int p[N];
void solve() {
  int n, m; cin >> n >> m;
  vector<int> s(m + 1);
  for (int i = 1; i <= m; i++) {
    cin >> s[i];
  }
  if (m < log2(n) + 1) {
    cout << -1 << '\n';
    return;
  }
  for (int i = 1; i <= n; i++) {
    cout << s[m - p[i]] << ' ';
  }
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 2; i < N; i++) {
    if (p[i]) continue;
    for (int j = i; j < N; j += i) {
      int x = j;
      while (x % i == 0) x /= i, ++p[j];
    }
  }
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}