#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <functional>
#include <algorithm>
#include <math.h>
using namespace std;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long a, b, c;
    int t;

    int n, m;
    cin >> n;
    vector<vector<char>> candy(n+2, vector<char>(n+2, 0));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> candy[i][j];
        }
    }
    int mx = -1;
    function <void(int)> garo = [&](int k){
        int bomb=1;
        char cur='Q';
        for(int i=1;i<=n;i++){
            if(cur!=candy[k][i]){
                cur = candy[k][i];
                mx = max(mx, bomb);
                bomb=1;
            }
            else{
                bomb++;
            }
        }
        mx = max(mx, bomb);
    };
    function <void(int)> sero = [&](int k){
        int bomb=1;
        char cur='Q';
        for(int i=1;i<=n;i++){
            if(cur!=candy[i][k]){
                cur = candy[i][k];
                mx = max(mx, bomb);
                bomb=1;
            }
            else{
                bomb++;
            }
        }
        mx = max(mx, bomb);
    };
    for(int i=1;i<=n;i++){
        garo(i);
    }
    for(int i=1;i<=n;i++){
        sero(i);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            swap(candy[i][j], candy[i+1][j]);
            garo(i);
            sero(j);
            if(i+1<=n)
                garo(i+1);
            swap(candy[i][j], candy[i+1][j]);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            swap(candy[i][j+1], candy[i][j]);
            sero(j);
            garo(i);
            if(j+1<=n)
                sero(j+1);
            swap(candy[i][j], candy[i][j+1]);
        }
    }
    cout << mx;
    
    return 0;
}