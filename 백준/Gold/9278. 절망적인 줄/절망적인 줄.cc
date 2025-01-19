#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <math.h>
using namespace std;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long a, b, c;
    int t;
    int n, m, k;
    int mi = 1e9;
    string s;
    while(getline(cin, s)){
        int total = s.size();
        int t_50 = total/2;
        vector <vector<int>> dp(total+1, vector<int>(t_50+1, 0));
        if(s[0]!=')') dp[1][1]=1;//총 개수가 1개, 50원도 1개(여유분 느낌) '('
        for(int i=1;i<s.size();i++){
            if(s[i]==')'){
                for(int j=1;j<=t_50;j++){
                    dp[i+1][j-1] += dp[i][j]%1000000;
                }
            }
            else if(s[i]=='('){
                for(int j=1;j<=t_50;j++){
                    dp[i+1][j] += dp[i][j-1]%1000000;
                }
            }
            else{
                for(int j=1;j<=t_50;j++){
                    dp[i+1][j] += dp[i][j-1]%1000000;
                }
                for(int j=1;j<=t_50;j++){
                    dp[i+1][j-1] += dp[i][j]%1000000;
                }
            }
        }
        cout << dp[total][0]%1000000 << '\n';
    }

    return 0;
}