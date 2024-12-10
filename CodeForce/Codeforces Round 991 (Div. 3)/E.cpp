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
long long mi = 1e16;
int total=0;
int main()
{
    ios_base ::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, k;
    int a, b;

    cin >> n;
    while(n--){
        string s1, s2, s3;
        cin >> s1 >> s2 >> s3;

        a = s1.size();
        b = s2.size();

        vector <vector<int>> dp(a+1, vector<int>(b+1, a+b+1)); //a+1개, b+1개 a+b+1로 채우기
        dp[0][0] = 0;
        for(int i=0;i<=a;i++){
            for(int j=0;j<=b;j++){
                if(i<a){
                    dp[i+1][j] = min(dp[i+1][j], dp[i][j]+(s1[i]!=s3[i+j]));
                }
                if(j<b){
                    dp[i][j+1] = min(dp[i][j+1], dp[i][j]+(s2[j]!=s3[i+j]));
                }
            }
        }
        cout << dp[a][b]<<'\n';
    }
    return 0;
}