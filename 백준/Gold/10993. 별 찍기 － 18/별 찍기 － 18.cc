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
    int n, m, k, t;
    int o_1, o_2;
    
    cin >> n;
    int s_n = n;

    vector<int> weight(11, 0);
    vector<int> height(11, 0);
    
    weight[1] = height[1] = 1;
    for(int i=2;i<=n;i++){
        weight[i] = 2*weight[i-1] + 3;
        height[i] = 2*height[i-1] + 1;
    }
    //2n+3개씩 늘어남.(가로) 1, 5, 13, 29
    //세로는 2n+1씩 늘어남. 1, 3, 7, 15
    vector<vector<char>> v(height[n], vector<char>(weight[n], ' '));
    int x = 0;
    int y = 0;

    if(n%2==1){
        x = height[n]-1;
    }

    n++;
    while(n--){
        if(n%2==0){ // 짝수 차례
            for(int i=0;i<weight[n];i++){
                v[x][y+i] = '*';
            }
            for(int i=0;i<height[n];i++){
                v[x+i][y+i] = '*';
            }
            for(int i=0;i<height[n];i++){
                v[x+i][y+weight[n] -1 - i] = '*';
            }
            x+=height[n-1];
        }
        else{
            for(int i=0;i<weight[n];i++){
                v[x][y+i] = '*';
            }
            for(int i=0;i<height[n];i++){
                v[x-i][y+i] = '*';
            }
            for(int i=0;i<height[n];i++){
                v[x-i][y+weight[n] -1 - i] = '*';
            }
            x-=height[n-1];
        }
        y += height[n-1]+1;
    }

    if(s_n%2==0){
        for(int i=0;i<height[s_n];i++){
            for(int j=0;j<weight[s_n]-i;j++){
                cout << v[i][j];
            }cout << '\n';
        }
    }
    else if(s_n%2==1){
        for(int i=0;i<height[s_n];i++){
            for(int j=0;j<weight[s_n]/2+1+i;j++){
                cout << v[i][j];
            }cout << '\n';
        }
    }

    return 0;
}