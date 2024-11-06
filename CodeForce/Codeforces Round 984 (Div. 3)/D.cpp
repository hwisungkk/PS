/*https://codeforces.com/contest/2036/problem/D*/
  while (tt--) {
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    for (int i = 0; i < h; i++) {
      cin >> s[i];
    }
    int ans = 0;
    for (int r = 0; r + r <= min(h - 1, w - 1); r++) {
      string t = "";
      for (int j = r + 1; j < w - r; j++) {
        t += s[r][j];
      }
      for (int i = r + 1; i < h - r; i++) {
        t += s[i][w - 1 - r];
      }
      for (int j = w - 2 - r; j >= r; j--) {
        t += s[h - 1 - r][j];
      }
      for (int i = h - 2 - r; i >= r; i--) {
        t += s[i][r];
      }
      t += t.substr(0, 3);
      for (int i = 0; i <= int(t.size()) - 4; i++) {
        if (t.substr(i, 4) == "1543") {
          ans += 1;
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}