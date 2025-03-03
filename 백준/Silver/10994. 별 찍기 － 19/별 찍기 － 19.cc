#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <queue>
#include <set>
#include <algorithm>
#include <math.h>
using namespace std;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int a, b, c, d;
    long long n, m, t;
    cin >> n;
    vector<vector<char>> v(4*n-3, vector<char>(4*n-3, ' '));

    function <void(int, int)> jae = [&](int x, int y){
        for(int i=x;i<4*n-3-x;i++){
            for(int j=y;j<4*n-3-y;j++){
                if(i==x || i== 4*n-4-x || j==y || j==4*n-4-y){
                    v[i][j] = '*';
                }
            }
        }
        if(x< 2*n-1){
            jae(x+2, y+2);
        }
    };
    jae(0,0);

    for(int i=0;i<4*n-3;i++){
        for(int j=0;j<4*n-3;j++){
            cout << v[i][j];
        }cout << '\n';
    }

    return 0;
}