#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <math.h>
using namespace std;
int dx[4] ={-1,1,0,0};
int dy[4]={0,0,1,-1};
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> v;
    int a, b, c;
    
    cin >> a >> b >> c;
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    sort(v.begin(), v.end());
    cout << v[1];
    return 0;
}