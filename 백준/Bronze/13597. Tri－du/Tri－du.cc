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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c, d;
    long long n, m, k, t;
    int idx = 1;

    cin >> n >> m;

    if(n==m)cout << n;
    else cout << ((n>m)?n:m);

    return 0;
}
