#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <queue>
#include <set>
#include <algorithm>
#include <math.h>
using namespace std;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long a, b, c;
    int n, m, t;
    cin >> a >> b;
    long long ans=1;
    for(int i=2;i<=a;i++){
        ans *= i;
        ans %= b; 
    }
    cout << ans%b;

    return 0;
}