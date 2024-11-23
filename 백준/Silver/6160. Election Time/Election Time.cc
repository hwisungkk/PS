#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, K;
    cin >> N >> K;
    
    vector<pair<pair<int, int>, int>> cows(N);  // {(A_i, B_i), index}
    
    for (int i = 0; i < N; i++) {
        cin >> cows[i].first.first >> cows[i].first.second;
        cows[i].second = i + 1;  // 1-based index
    }
    
    sort(cows.begin(), cows.end(), [](const auto& a, const auto& b) {
        return a.first.first > b.first.first;  
    });

    vector<pair<int, int>> secondCows;
    for (int i = 0; i < K; i++) {
        secondCows.push_back({cows[i].first.second, cows[i].second});
    }

    sort(secondCows.begin(), secondCows.end(), greater<pair<int, int>>());

    cout << secondCows[0].second << endl;

    return 0;
}