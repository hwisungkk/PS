#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <functional>
#include <math.h>
using namespace std;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, k;
    int a, b, c, d;
    string s;
    map<string, priority_queue<int, vector<int>, less<int>>> mp;
    cin >> n;
    long long total=0;
    for(int i=0;i<n;i++){
        cin >> a;
        if(a==1){ //고릴라 상품
            cin >> s;
            cin >> b;
            for(int j=0;j<b;j++){ //집어넣는거
                cin >> c;
                mp[s].push(c);
            }
        }
        else if(a==2){ //삼품을 삼
            cin >> s;
            cin >> b;
            for(int j=0;j<b;j++){
                if(mp[s].empty())break;
                total += mp[s].top();
                mp[s].pop();
            }
        }
    }
    cout << total;

    return 0;
}