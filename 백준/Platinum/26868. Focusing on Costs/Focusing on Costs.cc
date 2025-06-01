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
vector<string> ansv;

void jae(int a, int b) {
    if (a==b) {
        ansv.push_back("cos");
        return;
    }

    if (a < b) {
        jae(a, b - a);
        ansv.push_back("atan");
        ansv.push_back("sin");
    } else {
        jae(b, a);
        ansv.push_back("atan");
        ansv.push_back("sin");
        ansv.push_back("acos");
        ansv.push_back("tan");
    }
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long mod = 1e9+7;
        
    bool flag=0; 
    int a, b, c, d;
    long long n, m, t, k;
    long long ans = 0;
    int cur = 0;

    cin >> a >> b;

    jae(a*a,b*b);
    cout << ansv.size() << '\n';

    for(string s:ansv){
        cout << s << ' ';
    }

    return 0;
}

