#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;
int n = 0;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long a, b, c, total = 0;
    long long block = 0;
    int m; 
    cin >> n;
    char ch;
    while(n--){
        cin >> m;
        vector <int> v(m);
        vector <int> down(m);
        vector <pair<int, int>> point;
        int mx = -1;
        for(int i=0;i<m;i++){
            cin >> v[i];
            if(mx<v[i]){
                mx=v[i];
                point.push_back({i, v[i]});
            }
            down[i]=mx;
        }
        vector<int> mi;
        point.push_back({m,m});
        for(int i=0;i<=point.size()-2;i++){
            int min = 1000000;
            for(int j=point[i].first;j<point[i+1].first;j++){
                if(min>v[j])min=v[j];
            }
            mi.push_back(min);
        }
        for(int i=point.size()-3;i>=0;i--){
            if(point[i].second > mi[i+1]){
                mi[i] = min(mi[i], mi[i+1]);
                
                for(int j=point[i].first;j<point[i+1].first;j++){
                    down[j]=point[i+1].second;
                    point[i].second = point[i+1].second;
                }
            }
        }
        for(int i=0;i<m;i++){
            cout <<down[i] << " ";
        }cout << '\n';
    }
    return 0;
}
/*
8 8 << 4
5 8 << 3
3 6 << 2
1 4 << 1
0 2 << 0
*/
/*
5 - 0
3 - 1
1 - 2
2 - 3
*/
