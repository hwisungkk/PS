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
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long a, b, c;
    int t;

    string s;
    int n, m;
    cin >> t;
    while(t-->0){
        cin >> a;
        double total=0;
        double d;
        for(int i=0;i<a;i++){
            cin >> s >> n >> d;
            total += n*d;
        }
        cout << fixed;
        cout.precision(2);
        cout << '$' << total << '\n';
    }
    
    return 0;
}