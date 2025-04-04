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
    char ch;
    
    string s;
    cin >> n;
    vector<pair<int, int>> v;
    for(int i=0;i<n;i++){
        cin >> a >> b;
        v.push_back({b,a}); //끝, 시작
    }
    sort(v.begin(), v.end());
    priority_queue<int> pq;
    pq.push(0);
    int cnt=0;
    for(int i=0;i<n;i++){
        if(pq.top() <= v[i].second){
            pq.push(v[i].first);
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}