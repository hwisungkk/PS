#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    double d = (double)n/m;

    if(d<0.2)cout << "weak";
    else if(d<0.4)cout<<"normal";
    else if(d<0.6)cout<<"strong";
    else cout<<"very strong";

    return 0;
}