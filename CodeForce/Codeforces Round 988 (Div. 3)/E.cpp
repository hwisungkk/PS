#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <algorithm>
#include <math.h>
using namespace std;
int al = 0;
int m;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long a, b, c, total = 0;
    long long count = 0;
    int ma = 0;
    int ans = 100000000;
    long long n, k = -1;
    string s1, s2;
    using namespace std;
    int tt;
    cin >> tt;
    while (tt--){
        int n;
        cin >> n;
        auto Ask = [&](int l, int r){
            if (r - l <= 1){
                return 0;
            }
            cout << "? " << l + 1 << " " << r << endl;
            int got;
            cin >> got;
            return got;
        };
        int x = Ask(0, n);
        if (x == 0){
            cout << "! IMPOSSIBLE" << endl;
            continue;
        }
        string s = "";
        for (int i = 0; i < n; i++){
            int y = Ask(i + 1, n);
            if (y == x){
                s += "1";
            }
            else{
                s += "0";
                if (y == 0){
                    s += string(x, '1');
                    s.resize(n, '0');
                    break;
                }
                x = y;
            }
        }
        cout << "! " << s << endl;
    }
    return 0;
}