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
    int a, b, c, count=0;
    int ma = -100000;
    int n, m, k=-1;
    int dp[10000][3]={0};
    int kc[10000]={0};
    string s;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> kc[i];
    }
    for(int i=1;i<=n-1;i++){
        dp[i][0] = dp[i-1][2]+kc[i];//처음 오를 때
        dp[i][1] = dp[i-1][0]+kc[i];//두번째 오를 때
        dp[i][2] = max(dp[i-1][0], dp[i-1][1]);//안 오를 때
    }
    cout << max({dp[n-1][0], dp[n-1][2]}) + kc[n];
    
    return 0;
}