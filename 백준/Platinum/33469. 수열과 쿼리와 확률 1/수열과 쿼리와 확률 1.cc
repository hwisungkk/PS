#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <functional>
#include <algorithm>
#include <math.h>
#include <map>
using namespace std;
string s;
long long ans = 0;
const long long MOD = 1e9 + 7;

// 거듭제곱 (모듈러)
long long powmod(long long x, long long y) {
    long long res = 1;
    x %= MOD;

    while (y) {
        if (y & 1) res = res * x % MOD;
        x = x * x % MOD;
        y >>= 1;
    }

    return res;
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
        
    int a, b, c, d;
    long long n, m, t;
    bool flag=1; 

    cin >> n >> m;
    long long ret = 1;

    for(int i=1;i<=n;i++){
        long long tmp;
        cin >> tmp;
        ret = ret * i % MOD;
    }
    char ch;
    cin >> ch;

    if (c == 'S') { // S일 땐 변하는게 없는 듯??
        cout << "1\n";
        return 0;
    }

    long long v_2 = (MOD + 1) / 2;
    long long v_4 = (MOD + 1) / 4;

    ret = ret * powmod(powmod(n, n), MOD - 2) % MOD;
    ret = ret * v_2 % MOD;
    ret = (ret + (n + 1) * v_4 % MOD) % MOD;
    ret = powmod(ret, m);

    cout << ret << '\n';

    return 0;
}
