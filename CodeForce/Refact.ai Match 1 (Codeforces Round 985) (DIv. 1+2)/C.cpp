#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;
int al = 0;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a, b, c, total = 0;
    long long count = 0;
    int ma = -1000;
    long long n, m, k = -1;
    int dp[50][1000] = {0};
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        int dp[3] = {0, -1, -1};
        for (int i = 0; i < n; i++){
            dp[2] = max(dp[2], dp[1]); //쉬었다가 깬거. 만약 작아졌다면 계속 쉬는게 나으니까. 깬게 나으면 유지하고.
            dp[1] = max(dp[1], dp[0]); //0이 1보다 더 크면 그 때 쉬면 되니까. 쉰게 더 크면 유지하고.
            for (int j = 0; j < 3; j++){
                if (j == 1){
                    continue;
                }
                if (a[i] > dp[j]){
                    dp[j]++;
                }
                else if (a[i] < dp[j]){
                    dp[j]--;
                }
            }
        }

        cout << max(dp[1], dp[2]) << "\n"; //dp[0]을 고려안하는 이유는 한번이라도 쉬었어야 하니까? 인 듯.
    }
    return 0;
}