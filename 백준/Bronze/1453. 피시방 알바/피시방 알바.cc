#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <math.h>
using namespace std;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b, c;
    int n, m, t;
    char c1, c2, c3;

    cin >> a;
    vector<int> v(101, 0);
    int ans=0;
    for(int i=0;i<a;i++){
        cin >> b;
        if(v[b]==0)v[b]=1;
        else ans++;
    }
    cout << ans;

    return 0;
}