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
bool compare(pair<int, int> a, pair<int, int> b){
    if(a.second<b.second)return 1;
    else if(a.second==b.second){
        if(a.first<b.first)return 1;
        else return 0;
    }
    else return 0;
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b, c;
    int n, m, t;
    char c1, c2, c3;

    cin >> n;
    vector<pair<int, int>> v;
    for(int i=0;i<n;i++){
        cin >> a >> b;
        v.push_back({a,b});
    }
    sort(v.begin(), v.end(), compare);
    int end = 0;
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(v[i].first >= end){
            end = v[i].second;
            cnt++;
        }
    }
    cout << cnt;

    return 0;
}