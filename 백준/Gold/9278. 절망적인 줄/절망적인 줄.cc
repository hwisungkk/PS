#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    while (getline(cin, s)) {
        int n = s.length();
        int h = n/2;

        vector<vector<int>> dp(n + 1, vector<int>(h + 1, 0));
        
        if (s[0] != ')') {
            dp[0][1] = 1;
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= h; j++) {
                if (j != 0 && s[i] != ')') {
                    dp[i][j] = (dp[i-1][j-1] + dp[i][j]) % 1000000;
                }
                if (j != h && s[i] != '(') {
                    dp[i][j] = (dp[i-1][j+1] + dp[i][j]) % 1000000;
                }
            }
        }
        cout << dp[n-1][0] << '\n';
    }

    return 0;
}