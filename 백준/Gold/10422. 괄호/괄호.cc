#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <math.h>
using namespace std;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long a, b, c;
    int t;
    int n, m, k;
    int mi = 1e9;
    cin >> t;
    while(t-->0){
        cin >> n;
        if(n%2==1){
            cout << 0 << '\n';
            continue;
        }
        int open = n/2;
        vector<vector<long long>> dp(n+1, vector<long long>(open+1, 0)); //i는 총, j는 열린 괄호
        dp[1][1] = 1;
        for(int i=1;i<n;i++){
            for(int j=0;j<open;j++){
                dp[i+1][j] += dp[i][j+1]%1000000007;
            }
            
            for(int j=1;j<=open;j++){
                dp[i+1][j] += dp[i][j-1]%1000000007;
            }
        }
        cout << dp[n][0] %1000000007 << '\n';
    }

    return 0;
}