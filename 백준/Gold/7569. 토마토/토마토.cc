#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;
int dx[6] = {0, 0, 1, -1, 0, 0};
int dy[6] = {1, -1, 0, 0, 0, 0};
int dh[6] = {0, 0, 0, 0, 1, -1};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m = 0;
    int h, a, count = 0;
    int check = 0;
    int t[105][105][105];
    queue<tuple<int, int, int>> q;
    tuple<int, int, int> tq;
    for (int i = 0; i <= 104; i++){
        for (int j = 0; j <= 104; j++){
            for (int k = 0; k <= 104; k++){
                t[i][j][k] = -1;
            }
        }
    }
    cin >> n >> m >> h;
    for (int i = 1; i <= h; i++){
        for (int j = 1; j <= m; j++){
            for (int k = 1; k <= n; k++){
                cin >> t[i][j][k];
                if (t[i][j][k] == 1){
                    q.push({i, j, k});
                }
            }
        }
    }
    while (!q.empty()){
        tq = q.front();
        q.pop();
        for (int p = 0; p < 6; p++){
            if (t[get<0>(tq) + dh[p]][get<1>(tq) + dy[p]][get<2>(tq) + dx[p]] == 0){
                t[get<0>(tq) + dh[p]][get<1>(tq) + dy[p]][get<2>(tq) + dx[p]] 
                = t[get<0>(tq)][get<1>(tq)][get<2>(tq)] + 1;
                count = t[get<0>(tq)][get<1>(tq)][get<2>(tq)];
                q.push({(get<0>(tq) + dh[p]), (get<1>(tq) + dy[p]), (get<2>(tq) + dx[p])});
            }
        }
    }
    for (int i = 1; i <= h; i++){
        for (int j = 1; j <= m; j++){
            for (int k = 1; k <= n; k++){
                if (t[i][j][k] == 0){
                    cout << -1;
                    return 0;
                }
            }
        }
    }
    cout << count;
    return 0;
}