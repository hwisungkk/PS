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
    cin >> a >> b;
    count=1;
    while(1){
        if(b==a){
            break;
        }
        if(a>b){
            count=-1;
            break;
        }
        if(b%10==1){
            b/=10;
            count++;
        }
        else if(b%2==0){
            b/=2;
            count++;
        }
        else{
            count = -1;
            break;
        }
    }
    cout << count;
    return 0;
}