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
    vector<vector<char>> v(n, vector<char>(n));

    function <void(int, int, int, int, int)> jae = [&](int x, int y, int size, int sx, int sy){
        if(x >= (sx + size/3) && x < (sx + size*2/3) && y >= (sy + size/3) && y < (sy + size*2/3)){
            chk = 1;
        }
        else{
            if(size > 3){
                sx = x / (size/3) * (size/3);
                sy = y / (size/3) * (size/3);
                jae(x, y, size/3, sx, sy);
            }
        }
    };

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            chk = 0;
            jae(i,j,n,0,0);
            if(!chk)v[i][j]='*';
            else v[i][j] = ' ';
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << v[i][j];
        }cout << '\n';
    }
    return 0;
}