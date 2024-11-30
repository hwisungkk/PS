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
    char c1, c2, c3, c4;
    cin >> a;
    cin >> b >> c;
    if(a==1)k=0;
    else{
        if(b==1){
            if(c==1 || c==a)k=2;
            else k=3;
        }
        else if(b==a){
            if(c==1 || c==a)k=2;
            else k=3;
        }
        else if(c==1){
            if(b==1 || b==a)k=2;
            else k=3;
        }
        else if(c==a){
            if(b==1 || b==a)k=2;
            else k=3;
        }
        else k=4;
    }
    cout << k;
    return 0;
}