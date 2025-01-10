#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

int main()
{
    int k, n, d;
    cin >> k >> n >> d;

    pair<pair<int, int>, int> drivers[101];

    for (int i = 1; i <= n; ++i) {
        drivers[i] = make_pair(make_pair(0, -1), i);
    }

    // 점수 업데이트
    for (int i = 0; i < d; ++i) {
        int v, t;
        cin >> v >> t;
        if (t == drivers[v].first.first % k + 1) {
            drivers[v].first.first++; 
            drivers[v].first.second = i; 
        }
    }
    sort(drivers + 1, drivers + n + 1, [](auto &lhs, auto &rhs) {
        if (lhs.first.first != rhs.first.first)
            return lhs.first.first > rhs.first.first; 
        return lhs.first.second < rhs.first.second; 
    });

    for (int i = 1; i <= n; ++i) {
        cout << drivers[i].second << (i < n ? ' ' : '\n');
    }

    return 0;
}
