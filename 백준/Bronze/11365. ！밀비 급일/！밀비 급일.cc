#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <functional>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m, t;
    int a, b, c;

    string s;
    while(1){
        getline(cin, s);
        if(s=="END")break;

        for(int i=s.size()-1;i>=0;i--){
            cout << s[i];
        }cout << '\n';
    }
    return 0;
}