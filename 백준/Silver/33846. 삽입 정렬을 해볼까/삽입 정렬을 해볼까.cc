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
    long long n, m, t, k;
    bool flag=0; 

    string s;
    long long ans=0;

    cin >> n >> m;
    vector<int> v(m);
    vector<int> v2(n-m);
    for(int i=0;i<m;i++){
        cin >> v[i];
    }
    for(int i=0;i<n-m;i++){
        cin >> v2[i];
    }
    sort(v.begin(), v.end());
    for(int i=0;i<m;i++){
        cout << v[i] << ' ';
    }
    for(int i=0;i<n-m;i++){
        cout << v2[i] << ' ';
    }

    return 0;
}
