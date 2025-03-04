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
long long gcd(long long a, long long b){
    if(a<b)swap(a,b);
    while(b){
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
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
    
    vector<int> v(m+1); //정원원
    for(int i=1;i<=m;i++){
        cin >> v[i];
    }
    vector<vector<int>> success(n+1);
    vector<vector<int>> sin(m+1);

    for(int i=1;i<=n;i++){ //1차
        while(1){
            cin >> a;
            if(a==-1)break;
            sin[a].push_back(i);
        }
    }
    for(int i=1;i<=m;i++){
        if(sin[i].size() <= v[i]){ //자리가 있으면
            for(int j=0;j<sin[i].size();j++){
                success[sin[i][j]].push_back(i);
            }
            v[i] -= sin[i].size();
            sin[i].clear();
        }
    }
    for(int i=1;i<=n;i++){ //2차
        while(1){
            cin >> a;
            if(a==-1)break;
            sin[a].push_back(i);
        }
    }
    for(int i=1;i<=m;i++){
        if(sin[i].size() <= v[i]){ //자리가 있으면
            for(int j=0;j<sin[i].size();j++){
                success[sin[i][j]].push_back(i);
            }
            v[i] -= sin[i].size();
        }
    }
    for(int i=1;i<=n;i++){
        sort(success[i].begin(), success[i].end());
    }
    for(int i=1;i<=n;i++){
        if(success[i].size()==0){
            cout << "망했어요";
        }
        for(int j=0;j<success[i].size();j++){
            if(j==success[i].size()-1)cout << success[i][j];
            else cout << success[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}