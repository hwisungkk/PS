#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <stack>
#include <set>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;
int v[101];
int n, m;
int main()
{
    ios_base ::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    
    long long k;
    long long a, b, c, d;

    string s;
    cin >> n;
    vector<vector<int>> graph(n+1);
    for(int i=0;i<n-1;i++){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int count=0;
    vector<int> check(n+1, 0);
    int save = 0;
    int ma=0;
    for(int i=1;i<=n;i++){
        if(ma < graph[i].size()){
            ma = graph[i].size();
            save = i;
        }
    }
    if(graph[save].size()==n-1){
        cout << n-1;
    }
    else cout << n;
    
    return 0;
}