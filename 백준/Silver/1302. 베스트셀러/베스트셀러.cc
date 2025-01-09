#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <stack>
#include <map>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
    long long mi = 1e16;
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a, b, c;
    int n;
    int t;
    cin >> t;
    map<string, int> m;
    while(t-->0){
        string s;
        cin >> s;
        if (m.find(s) == m.end())
			m.insert({s, 1});
		else
			m[s]++;
    }
    int ma = -1;
    string s2;
    for(auto it : m){
        if(it.second > ma){
            ma = it.second;
            s2 = it.first;
        }
    }cout << s2;

    return 0;
}
