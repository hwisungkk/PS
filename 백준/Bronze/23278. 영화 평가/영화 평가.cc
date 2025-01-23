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
vector <vector <int>> sudo(9, vector<int>(9, 0));
vector <vector <int>> real_sudo(9, vector<int>(9, 0));
int complete = 0;
int cnt=0;
int ma = -1;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long a, b, c;
    int t;
    int n, m, k;
    int mi = 1e9;
    cin >> n >> m >> k;
    vector <int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    cout << fixed;
    cout.precision(10);
    int total=0;
    for(int i=m;i<n-k;i++){
        total += v[i];
    }
    cout << (double)total / (n-m-k);

    return 0;
}