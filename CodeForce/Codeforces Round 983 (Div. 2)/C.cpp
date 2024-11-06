/*https://codeforces.com/contest/2032/problem/C*/
//   std::sort(a.begin(), a.end());
 
//   int ans = n;
//   for (int l = 0, r = 0; l < n; ++l) {
//     while (r < n && (r - l < 2 || a[r] < a[l] + a[l + 1])) {
//       r += 1;
//     }
//     ans = std::min(ans, n - (r - l));
//   }
 
//   std::cout << ans << "\n";
// }