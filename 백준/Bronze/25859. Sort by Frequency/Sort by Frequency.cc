#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string s;
    cin >> s;

    int frequency[26] = {0};

    for (char c : s) {
        frequency[c - 'a']++;
    }

    vector<pair<int, char>> freq_vec;

    for (int i = 0; i < 26; i++) {
        if (frequency[i] > 0) {
            freq_vec.push_back({frequency[i], i + 'a'}); 
        }
    }

    sort(freq_vec.begin(), freq_vec.end(), [](const pair<int, char>& a, const pair<int, char>& b) {
        if (a.first == b.first) return a.second < b.second; 
        return a.first > b.first; 
    });

    for (auto& p : freq_vec) {
        cout << string(p.first, p.second);
    }

    return 0;
}
