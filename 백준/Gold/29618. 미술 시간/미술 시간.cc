#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <functional>
#include <algorithm>
#include <math.h>
using namespace std;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a, b, c;
    int t;

    int n, m;
    cin >> n >> m;
    vector<int> v(n+1, 0);
    set <int> s;
    for(int i=1;i<=n;i++){
        s.insert(i);
    }
    queue<int> q;

    for(int i=0;i<m;i++){
        cin >> a >> b >> c;
        for(auto it = s.lower_bound(a); it!=s.end() && *it<=b;it++){
            v[*it]=c;
            q.push(*it);
        }
        while(!q.empty()){
            s.erase(q.front());
            q.pop();
        }
    }
    for(int i=1;i<=n;i++){
        cout << v[i] << ' ';
    }
    return 0;
}