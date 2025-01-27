#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <functional>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a, b, c;
    int t;

    string s;
    int n, m;
    cin >> n;
    
    long long ans=0;
    for(int i=1;i<=n;i++){
        ans += (n/i) * i;
    }
    cout << ans;
    return 0;
}