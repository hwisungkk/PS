#define ll long long
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
#include <map>
using namespace std;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long mod = 1'000'000;

    bool flag = 0;
    long long a, b, c, d;
    long long n, m, t, k = 0;
    long long ans = 1e16;

    cin >> n;

    if(n<=6)cout<<"NO\n";
    else{
        if(n%2){
            cout<<"YES\n";
            cout<<"1 + 4\n";
            cout<<"5 * 5\n";
            cout<<"6 * 7\n";
            cout<<"42 * 2\n";
            cout<<"84 - 3\n";
            cout<<"25 * 81\n";
            for(int i=8;i<=n;i+=2){
                cout<<i+1 << " - " << i << '\n';
                cout<<"2025 * 1\n";
            }
        }
        else{
            cout<<"YES\n";
            cout<<"1 + 2\n";
            cout<<"3 * 3\n";
            cout<<"9 * 5\n";
            cout<<"4 * 8\n";
            cout<<"32 + 6\n";
            cout<<"38 + 7\n";
            cout<<"45 * 45\n";
            for(int i=9;i<=n;i+=2){
                cout<<i+1 << " - " << i << '\n';
                cout<<"2025 * 1\n";
            }
        }
    }

    //2025 = 3^4*5^2
    // 8은 (1+2)*3*5*((4*8)+6+7)
    // 9는 예제로

    return 0;
}