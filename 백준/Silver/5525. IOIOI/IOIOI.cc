#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <algorithm>
#include <math.h>
using namespace std;
int ar[130][130]={0};
int count1=0;
int count2=0;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a, b, c = 0, total = 0;
    char ch;
    int ma = -1000;
    int count =0;
    int n, m, z = 1;
    int ar[101][101] = {0};
    int check[1001];
    vector<int> v1;
    string s;
    int dp[1000001]={0};
    cin >> n >> m;
    cin >> s;
    for(int i=0;i<m-2;i++){
        if(s[i]=='I' && s[i+1]=='O' && s[i+2]=='I'){
            dp[i] = dp[i-2]+1;
            if(dp[i]>=n)count++;
        }
    }
    cout << count;
    return 0;
}