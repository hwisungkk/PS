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
        
    int a, b, c, d;
    int n, m, t, k;
    bool flag=0; 

    string s;

    cin >> n >> m >> t; //세로, 놓여있는 사다리, 가로 개수
    vector<vector<bool>> v(t+2, vector<bool>(n+2, 0));
    for(int i=0;i<m;i++){
        cin >> a >> b; //a~a+1로 넘어가고, b는 위에서 가는 것 2차원 배열 a 세로에 b를 체크하면 되지 않나?
        v[a][b]=1;
    }

    function <bool(void)> check = [&](){
        bool b=1;
        for(int i=1;i<=n;i++){
            int cur = i;
            for(int j=1;j<=t;j++){
                if(v[j][cur]==1){
                    cur = cur+1;
                }
                else if(v[j][cur-1]==1){
                    cur = cur-1;
                }
            }
            if(cur!=i){
                b=0;
                break;
            }
        }

        return b;
    };

    function <bool(int, int, int, int)> back = [&](int k, int dst, int x, int y){
        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=t;j++){
        //         cout << v[i][j] << ' ';
        //     }cout << '\n';
        // }
        // cout << "----\n";
        if(k==dst){
            flag = check();
            return flag;
        }
        for(int i=1;i<=t;i++){
            for(int j=y;j<=n;j++){
                if(!v[i][j] && !v[i][j+1] && !v[i][j-1]){
                    v[i][j]=1;
                    back(k+1, dst, i, j);
                    if(flag)return flag;
                    v[i][j]=0;
                }
            }
        }
        return flag;
    };

    if(check())cout << "0";
    else if(back(0, 1, 1, 1)){
        cout << "1";
    }
    else if(back(0, 2, 1, 1)){
        cout << "2";
    }
    else if(back(0, 3, 1, 1)){
        cout << "3";
    }
    else cout << "-1";


    return 0;
}
