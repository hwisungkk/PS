#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        int cntA = 0, cntB = 0;
        for (char c : s) {
            if (c == 'a') cntA++;
            else if (c == 'b') cntB++;
        }

        cout << min(cntA, cntB) << "\n";
    }
    return 0;
}
