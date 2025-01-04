#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <stack>
#include <set>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;
int n;
int ma=-1;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a, b, c, m;
    int t;
    cin >> t;
    while(t-->0){
        cin >> n;
        vector<int> score1(n,0);
        vector<int> score2(n,0);
        vector <vector<int>> dp(2, vector<int>(n));
        for(int i=0;i<2;i++){
            for(int j=0;j<n;j++){
                cin >> dp[i][j];
            }
        }
        score1[0] = dp[0][0];
        score2[0] = dp[1][0];
        score1[1] = score2[0] + dp[0][1];
        score2[1] = score1[0] + dp[1][1];
        for(int i=2;i<n;i++){
            score1[i] = max((score2[i-2]+dp[0][i]), score2[i-1]+dp[0][i]);
            score2[i] = max((score1[i-2]+dp[1][i]), score1[i-1]+dp[1][i]);
        }
        cout << max(score1[n-1], score2[n-1]) << '\n';
        
    }
    return 0;
}
