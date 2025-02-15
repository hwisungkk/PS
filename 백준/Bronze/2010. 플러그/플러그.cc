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
    
    int n, m, t;
    int a, b, c;
    cin >> n;
    int total=0;
    for(int i=0;i<n;i++){
        cin >> m;
        total += m;
    }
    cout << total - n + 1;


    return 0;
}