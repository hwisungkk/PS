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
    cin >> n >> m;
    z = m-n;
    if(z<=0)cout<<"Congratulations, you are within the speed limit!";
    else if(z<21)cout<<"You are speeding and your fine is $100.";
    else if(z<31)cout<< "You are speeding and your fine is $270.";
    else cout<< "You are speeding and your fine is $500.";
    return 0;
}