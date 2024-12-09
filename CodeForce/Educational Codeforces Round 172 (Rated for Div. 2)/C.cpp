#include <bits/stdc++.h>
 
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
 
void solve() {
    int n, k;
    std::cin >> n >> k;
    
    std::string s;
    std::cin >> s;
    
    std::vector<int> f(n);
    for (int i = n - 1; i >= 0; i--) {
        if (i < n - 1) {
            f[i] = f[i + 1];
        }
        if (s[i] == '1') {
            f[i]++;
        } else {
            f[i]--;
        }
    }
    f.erase(f.begin());
    std::sort(f.begin(), f.end(), std::greater());
    
    i64 sum = 0;
    for (int i = 1; i < n; i++) {
        sum += f[i - 1];
        if (sum >= k) {
            std::cout << i + 1 << "\n";
            return;
        }
    }
    std::cout << -1 << "\n";
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