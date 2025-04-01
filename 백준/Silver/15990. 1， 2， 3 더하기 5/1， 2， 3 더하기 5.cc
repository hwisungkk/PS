#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <functional>
#include <algorithm>
#include <math.h>
#include <map>
using namespace std;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
        
    int a, b, c, d;
    long long n, m, t;
    bool flag=1; 
    long long mod = 1000000009;

    vector<vector<long long>>dp(100001, vector<long long>(4,0));

    dp[1][1] = 1;
    dp[2][2] = 1;
    dp[3][1] = 1;
    dp[3][2] = 1;
    dp[3][3] = 1;

    for(int i=4;i<=100000;i++){
        for(int j=1;j<=3;j++){
            for(int k=1;k<=3;k++){
                dp[i][j] += dp[i-j][k];
            }
            dp[i][j] -= dp[i-j][j];
            dp[i][j]%=mod;
        }
    }
    cin >> t;
    while(t-->0){
        cin >> n;
        long long ans=0;
        for(int i=1;i<=3;i++){
            ans += dp[n][i];
        }
        cout << ans%mod << '\n';
    }

    return 0;
}