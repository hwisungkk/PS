#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;
int n = 0;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long a, b, c, total = 0;
    long long block = 0;
    int m;
    cin >> n >> m;
    queue <int> q;
    int dp[101][2]={0};
    for(int i=0;i<n+m;i++){
        cin >> a >> b;
        dp[a][0] = -1;
        dp[a][1] = b;
    }
    int mal = 1;
    q.push(1);
    dp[1][0]=0;
    while(1){
        mal=q.front();
        q.pop();
        for(int i=1;i<=6;i++){
            if(dp[mal+i][0]==0){
                dp[mal+i][0]=dp[mal][0]+1;
                q.push(mal+i);
            }
            else if(dp[mal+i][0]==-1 && dp[dp[mal+i][1]][0]==0){
                dp[dp[mal+i][1]][0] = dp[mal][0]+1;
                q.push(dp[mal+i][1]);
                dp[mal+i][0] = -3;
            }
        }
        if(dp[100][0]!=0)break;
    }
    cout << dp[100][0];
    return 0;
}
// 1 2 92 4 5 6