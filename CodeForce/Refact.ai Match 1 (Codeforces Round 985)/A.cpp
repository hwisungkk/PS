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
    string s1, s2;
    vector<int> v;
    cin >> n;
    for(int i=0;i<n;i++){
        count=0;
        cin >> a >> b >> c;
        m = b/c - a + 1;
        if(m<=0) cout << 0 << '\n';
        else cout<< m<< '\n';
    }
    return 0;
}