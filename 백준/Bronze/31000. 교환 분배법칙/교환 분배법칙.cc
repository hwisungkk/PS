#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k=1, a, b = 0, c = 0;
    long long count = 0;
    string s;
    string s2;
    vector<string> v;
    cin >> n;
    // for(int a=-n;a<=n;a++){
    //     for(int b=-n;b<=n;b++){
    //         for(int c=-n;c<=n;c++){
    //             if(a==0 || a+b+c == 1){
    //                 count++;
    //             }
    //         }
    //     }
    // }
    int dp[3001]={0};
    dp[1]= 13;
    for(int i=2;i<=3000;i++){
        dp[i] = dp[i-1] + 26 + 14*(i-2);
    }
    cout << dp[n];
}
//13 39 79 133 - 26 40 54 68
//a + b*c = (a+b)*(a+c)
//a = a^2 + a*(b+c)
// 1 = a + b + c;
//a==0, 2n+1^2