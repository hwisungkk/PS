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
string s;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
        
    int a, b, c, d;
    long long n, m, t, k;
    bool flag=1; 

    cin >> n >> m;
    vector<vector<int>> v1(n, vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> v1[i][j];
        }
    }
    cin >> m >> k;
    vector<vector<int>> v2(m, vector<int>(k));
    for(int i=0;i<m;i++){
        for(int j=0;j<k;j++){
            cin >> v2[i][j];
        }
    }
    vector<vector<int>> ans(n, vector<int>(k, 0));

    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            for(int t=0;t<m;t++){
                ans[i][j] += v1[i][t]*v2[t][j];
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            cout << ans[i][j] << ' ';
        }cout << '\n';
    }

    return 0;
}
