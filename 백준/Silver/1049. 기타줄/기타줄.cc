#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include<map>
#include <algorithm>
#include<math.h>
using namespace std;
int al=0;
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a, b, c=0, total=0;
    char ch;
    long long count=0;
    int ma = -1000;
    int n, m, z=1;
    int dp[10000]={0};
    char ar[30][30];
    vector <int> v1;
    vector <int> v2;
    string s;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> a >> b;
        v1.push_back(a);
        v2.push_back(b);
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    z = min(v2[0]*n, v1[0]*(n/6)+v2[0]*(n%6));
    cout << min(z, v1[0]*(n/6+1));
    return 0;
}
//a + b*c = (a+b)*(a+c)
//a = a^2 + a*(b+c)
// 1 = a + b + c;
//a==0, 2^2n+1