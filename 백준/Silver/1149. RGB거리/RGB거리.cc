#include <iostream>
#include <vector>
#include <string>
#include<math.h>
using namespace std;
int main() {
    int ar[60][60][60];
    double a, b, c;
    int n, m, k;
    int count = 0;
    int color[1001][3];
    int dp[1001][3];
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cin >> dp[i][j];
        }
    }
    for(int i=1;i<n;i++){
        dp[i][0] += min(dp[i-1][1], dp[i-1][2]);
        dp[i][1] += min(dp[i-1][0], dp[i-1][2]);
        dp[i][2] += min(dp[i-1][1], dp[i-1][0]);
    }
    m = min(dp[n-1][0], dp[n-1][1]);
    m = min(m, dp[n-1][2]);
    cout << m;
    return 0;
}
