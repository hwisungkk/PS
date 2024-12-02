#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <stack>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;
int al = 0;
vector <vector <int>> v(5001);
deque <int> d;
void dfs(int n, int k){
    d.push_back(n);
    if(n==k){
            cout << d.size() << '\n';
            while(!d.empty()){
                cout << d.front() << '\n';
                d.pop_front();
            }
            return;
        }
    for(int i=0;i<v[n].size();i++){
        dfs(v[n][i], k);
    }
    d.pop_back();
}
int main()
{
    ios_base ::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    long long a, b, c, total = 0;
    long long n, k = -1;
    int m;
    int t;
    string s1, s2;
    cin >> n >> m >> k;
    for(int i=0;i<m;i++){
        cin >> a >> b >> c;
        v[a].push_back(b);
        v[a].push_back(c);
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=0;j<v[i].size();j++){
    //         cout << v[i][j] << ' ';
    //     }cout << '\n';
    // }
    dfs(1, k);
    
    return 0;
}