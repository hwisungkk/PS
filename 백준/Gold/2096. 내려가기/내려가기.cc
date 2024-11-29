#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
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
    long long n, k = -1;
    int m;
    string s1, s2;
    int ar[3];
    int max_dp[3]={0};
    int min_dp[3]={0};
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cin >> ar[j];
        }
        a= ar[0]+max({max_dp[0], max_dp[1]});
        b= ar[1]+max({max_dp[0], max_dp[1], max_dp[2]});
        c= ar[2]+max({max_dp[1], max_dp[2]});
        max_dp[0]=a, max_dp[1]=b, max_dp[2]=c;

        a= ar[0]+min({min_dp[0], min_dp[1]});
        b= ar[1]+min({min_dp[0], min_dp[1], min_dp[2]});
        c= ar[2]+min({min_dp[1], min_dp[2]});
        min_dp[0]=a, min_dp[1]=b, min_dp[2]=c;
    }
    cout << max({max_dp[0], max_dp[1], max_dp[2]}) << ' ';
    cout << min({min_dp[0], min_dp[1], min_dp[2]});

    
}