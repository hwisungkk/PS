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
    long long a, b, c, total = 0;
    long long count = 0;
    int ma = 0;
    long long n, m, k = -1;
    string s1, s2;
    int j;
    cin >> n;
    while(n--){
        cin >> m;
        count =0;
        int ma2=-1;
        vector <int> v(m);
        vector <int> dp(m);
        dp[0]=1;
        for(int i=0;i<m;i++){
            int ma = 0;
            cin >> v[i];
            for(int j=0;j<i;j++){
                if(v[i]>=v[j]){
                    ma = max(dp[j], ma);
                }
            }
            dp[i]=ma+1;
            ma2=max(dp[i], ma2);
        }
        cout << m - ma2 << '\n';
    }
    //증가 부분 수열 구하고 빼기인 듯
    
    return 0;
}