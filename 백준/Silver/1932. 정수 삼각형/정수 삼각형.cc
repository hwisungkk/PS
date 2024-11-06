#include <iostream>
#include <vector>
#include <string>
#include<math.h>
using namespace std;
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a, b, c;
    int ma = -1;
    long long n, m, k;
    int dp[600][600]={0};
    int kc[600][600]={0};
    cin >> n;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cin >> kc[i][j];
        }
    }
    dp[1][1] = kc[1][1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            dp[i][j] =  max(dp[i-1][j-1], dp[i-1][j]) + kc[i][j];
        }
    }
    for(int i=1;i<=500;i++){
        if(ma<dp[n][i])ma=dp[n][i];
    }
    cout<< ma;
    
    return 0;
}