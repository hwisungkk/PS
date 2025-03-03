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
    if(n==1){
        cout << '*';
        return 0;
    }
    vector<vector<char>> v(4*n-1, vector<char>(4*n-3, ' '));
    for(int j=0;j<4*n-3;j++){
        v[0][j]='*';
        v[4*n-2][j]='*';
    }
    for(int i=1;i<4*n-2;i++){
        v[i][0] = '*';
    }
    int k =0;
    int cho = 0;
    int i = 4*n - 2;
    int j = 4*n - 4;
    while(1){
        
        
        i+=dx[k];
        j+=dy[k];
        v[i][j]='*';
        if(v[i+dx[k]+dx[k]][j+dy[k]+dy[k]]=='*'){
            k++;
        }
        k%=4;
        if(i==2*n && j == 2*n-2)break;
    }
    

    for(int i=0;i<4*n-1;i++){
        for(int j=0;j<4*n-3;j++){
            if(i==1){
                cout << v[i][0];
                break;
            }
            cout << v[i][j];
        }cout << '\n';
    }

    return 0;
}