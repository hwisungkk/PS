#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <stack>
#include <set>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;
int k, n;
bool compare(pair<string, string> a, pair<string, string> b){
    if(a.first==b.first){
        return a.second > b.second;
    }
    return a.first < b.first;

}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int m;
    int a, b, c;
    int t;
    cin >> m;
    vector <pair<string, string>> p;
    for(int i=0;i<m;i++){
        string s1, s2;
        cin >> s1 >> s2;
        p.push_back({s1,s2});
    }
    sort(p.begin(), p.end(), compare);
    for(int i=0;i<m;i++){
        cout << p[i].first << ' ' << p[i].second << '\n';
    }
    return 0;
}
//8 2 9 1 4 6 7 10
