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
    cin >> n;
    string s;
    for(int i=0;i<n;i++){
        cin >> s;
        cout << ((s[s.size()/2-1]==s[s.size()/2]) ? "Do-it\n" : "Do-it-Not\n");
    }
    return 0;
}