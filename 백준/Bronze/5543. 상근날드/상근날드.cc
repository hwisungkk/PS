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

    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    cout << min({a,b,c})+min(d,e)-50;
    return 0;
}