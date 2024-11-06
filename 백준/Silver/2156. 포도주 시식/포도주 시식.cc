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
    long long dp[10001][3]={0};
    int kc[10001]={0};
    string s;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> kc[i];
    }
    for(int i=1;i<=n;i++){
        dp[i][0] = dp[i-1][2]+kc[i];//처음 오를 때
        dp[i][1] = dp[i-1][0]+kc[i];//두번째 오를 때
        dp[i][2] = max({dp[i-1][0], dp[i-1][1], dp[i-1][2]});//안 오를 때
    }
    cout << max({dp[n][0], dp[n][1], dp[n][2]});
    return 0;
}