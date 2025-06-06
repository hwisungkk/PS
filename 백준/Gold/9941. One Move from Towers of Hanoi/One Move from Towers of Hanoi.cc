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
void move(long long k, int n, char from, char spare, char to, int idx) {
    if (n == 0) return;

    long long left_moves = (1LL << (n-1)) - 1;  // 왼쪽 서브트리 이동 수

    if (k <= left_moves) {
        move(k, n - 1, from, to, spare, idx);
    } else if (k == left_moves + 1) {
        cout << "Case " << idx << ": " << n << " " << from << " " << to << "\n";
    } else {
        move(k - left_moves - 1, n - 1, spare, from, to, idx);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c, d;
    long long n, m, k, t;
    int idx = 1;

    while (cin >> k >> n) {
        if (k == 0 && n == 0) break;
        move(k, n, 'A', 'B', 'C', idx);
        idx++;
    }

    return 0;
}
