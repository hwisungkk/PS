#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    string s = "qkj";

    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> p(3, vector<int>(n + 1));
        for (int i = 0; i < 3; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> p[i][j];
            }
        }

        vector<pair<char, int>> sol(n + 1, {'\0', -1});
        array<int, 3> mins = {n, n, n};  // Minimizing index

        for (int i = n - 1; i >= 1; i--) {
            int win = -1;
            for (int j = 0; j < 3; j++) {
                if (p[j][i] > p[j][mins[j]]) {
                    win = j;
                }
            }

            if (win == -1) continue;

            sol[i] = {s[win], mins[win]};

            for (int j = 0; j < 3; j++) {
                if (p[j][i] < p[j][mins[j]]) {
                    mins[j] = i;
                }
            }
        }

        if (sol[1].second == -1) {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
        vector<pair<char, int>> ans = {sol[1]};

        while (ans.back().second >= 0) {
            ans.push_back(sol[ans.back().second]);
        }

        ans.pop_back();
        cout << ans.size() << "\n";
        for (auto&& [c, i] : ans) {
            cout << c << " " << i << "\n";
        }
    }

    return 0;
}
