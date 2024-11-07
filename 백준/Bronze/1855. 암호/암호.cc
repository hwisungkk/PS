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
    string s;
    cin >> n;
    cin >> s;
    for(int i=0;i<s.size();i++){
        if((i/n)%2==0)
            ar[i/n][i%n]=s[i];
        else
            ar[i/n][n-(i%n)-1]=s[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<s.size()/n;j++){
            cout<<ar[j][i];
        }
    }
    return 0;
}