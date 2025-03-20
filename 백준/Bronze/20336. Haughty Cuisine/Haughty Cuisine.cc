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
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int a, b, c, d;
    int n, m, t;
    long long ans;
    string s;
    
    cin >> t;
    for(int i=0;i<t;i++){
        cin >> n;
        if(i==0)cout << n << '\n';
        for(int j=0;j<n;j++){
            cin >> s;
            if(i==0)
                cout << s << '\n';
        }
    }
    return 0;
}