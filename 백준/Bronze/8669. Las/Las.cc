#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    const int MAX_R = 1'000'000;
    vector<unsigned char> seen(MAX_R + 1, 0);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        long long g;
        int r;
        cin >> g >> r;
        if (!seen[r]) {
            seen[r] = 1;
            ans++;
        }
    }

    cout << ans << "\n";
    return 0;
}
