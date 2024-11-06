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
    cin >> s1;
    for(int i=0;i<s1.size()-3;i++){
        if(s1[i]=='k'&&s1[i+1]=='i'&&s1[i+2]=='c'&&s1[i+3]=='k')count++;
    }
    cout << count;
    return 0;
}