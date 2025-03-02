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
bool ch_sq(int n){
    int che = int(sqrt(n));
    if (che * che == n)return 1;
    else return 0;
}
int main()
{
    ios_base ::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    
    int a, b, c, d;
    int n, m, k, t;
    int o_1, o_2;

    cin >> n >> m;
    string s;
    vector<vector<int>> v(n, vector<int>(m));
    int mx = -1;
    for(int i=0;i<n;i++){
        cin >> s;
        for(int j=0;j<m;j++){
            v[i][j] = int(s[j]-48);
        }
    }
    int dx[8] = {0,0,-1,1,-1,1,-1,1}; //오른쪽, 왼쪽, 위, 밑, 왼대위, 왼대아래, 오대위, 오대아래
    int dy[8] = {1,-1,0,0,-1,1,1,-1};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int s_i = i, s_j = j;
            for(int k=0;k<8;k++){
                for(int x=1;x<=8;x++){
                    for(int y=1;y<=8;y++){
                    int num = v[i][j];
                    if(ch_sq(num)) mx = max(mx, num);
                        while(i+(dx[k]*x) >= 0 && i+(dx[k]*x) < n && j+(dy[k]*y) >= 0 && j+(dy[k]*y) < m){
                            i+=(dx[k]*x);
                            j+=(dy[k]*y);
                            num*=10;
                            num+=v[i][j];
                            if(ch_sq(num)) mx = max(mx, num);
                        }
                        i = s_i, j = s_j;
                    }
                }
            }
        }
    }
    cout << mx;

    return 0;
}