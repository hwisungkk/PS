#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<math.h>
using namespace std;
int al=0;
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a, b, c;
    long long count=0;
    int ma = -1000;
    int n, m, k=-1;
    long long dp[101][10]={0};
    int kc[10000]={0};
    string s;
    cin >> n;
    for(int i=1;i<10;i++){
        dp[1][i] = 1;
    }
    for(int i=2;i<=n;i++){
        dp[i][0] = dp[i-1][1] % 1000000000;
        for(int j=1;j<=8;j++){
            dp[i][j] = dp[i-1][j-1] % 1000000000 + dp[i-1][j+1]% 1000000000;
        }
        dp[i][9]= dp[i-1][8]% 1000000000;
    }
    for(int i=0;i<10;i++){
        count += dp[n][i] % 1000000000;
    }
    cout << count % 1000000000;
    return 0;
}