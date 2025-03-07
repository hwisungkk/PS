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
    int n, m, k, t;
    int o_1, o_2;
    cin >> n;
    
    cout << "? 1000000000" << endl;
    string s;
    cin >> s;
    cout << "\n! ";
    for (int i = s.size(); i > 0; i -= 9) {
        int start = max(i - 9, 0);
        cout << stoi(s.substr(start, i - start)) << ' ';
    }
    
    cout << endl;

    return 0;
}