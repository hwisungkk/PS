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
int k, n;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int m;
    int a, b, c;
    int t;
    string s1, s2;
    cin >> s1;
    cin >> s2;

    int ar[1001][1001]={0};
    int ans = -1;
    for(int i=1;i<=s1.size();i++){
        for(int j=1;j<=s2.size();j++){
            ar[i][j] = max({(ar[i-1][j-1]+(s1[i-1]==s2[j-1])), ar[i-1][j], ar[i][j-1]});
            if(ans<ar[i][j])ans=ar[i][j];
        }
    }
    cout << ans;
    return 0;
}
