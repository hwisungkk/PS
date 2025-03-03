#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <queue>
#include <set>
#include <algorithm>
#include <math.h>
using namespace std;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int a, b, c, d;
    long long n, m, t;
    cin >> n;
    int chk = 0;
    vector<vector<char>> v(n, vector<char>(2*n-1, 0));

    function <void(int, int)> jae = [&](int x, int y){
        v[x][y] = '*';
        v[x+1][y-1] = '*';
        v[x+1][y+1] = '*';
        v[x+2][y-2] = '*';
        v[x+2][y-1] = '*';
        v[x+2][y] = '*';
        v[x+2][y+1] = '*';
        v[x+2][y+2] = '*';
        if(x+3 < n){
            v[x+3][y-3]++;
            v[x+3][y+3]++;
        }
    };

    v[0][n-1] = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<2*n-1;j++){
            if(v[i][j]==1){
                jae(i,j);
            }
            else if(v[i][j]== '*'){
                continue;
            }
            else v[i][j] = ' ';
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<2*n-1;j++){
            cout << v[i][j];
        }cout << '\n';
    }
    return 0;
}