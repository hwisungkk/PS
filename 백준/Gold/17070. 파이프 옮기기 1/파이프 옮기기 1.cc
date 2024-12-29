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
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a, b, c, n, m, k;
    int t;

    cin >> n;
    vector <vector<int>> pipe (n+2, vector<int>(n+2, 0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> pipe[i][j];
        }
    }
    int dp[17][17][3]={0};
    dp[1][2][0] = 1;
    //dp 3차 삼차원 값은 0이 가로, 1이 세로, 2가 대각선.
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(pipe[i][j+1]==0)dp[i][j+1][0]+=dp[i][j][0]; //가로 -> 가로
            if(pipe[i][j+1]==0 && pipe[i+1][j]==0 && pipe[i+1][j+1]==0)dp[i+1][j+1][2]+=dp[i][j][0]; //가로 -> 대각
            if(pipe[i+1][j]==0)dp[i+1][j][1]+=dp[i][j][1]; //세로 -> 세로
            if(pipe[i][j+1]==0 && pipe[i+1][j]==0 && pipe[i+1][j+1]==0)dp[i+1][j+1][2]+=dp[i][j][1]; //세로 -> 대각
            if(pipe[i][j+1]==0)dp[i][j+1][0]+=dp[i][j][2]; //대각 -> 가로
            if(pipe[i+1][j]==0)dp[i+1][j][1]+=dp[i][j][2]; //대각 -> 세로
            if(pipe[i][j+1]==0 && pipe[i+1][j]==0 && pipe[i+1][j+1]==0)dp[i+1][j+1][2]+=dp[i][j][2]; //대각 -> 대각
        }
    }
    
    cout << dp[n][n][0]+dp[n][n][1]+dp[n][n][2];
    return 0;
}
